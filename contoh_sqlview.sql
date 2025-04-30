-- 1. SIMPLE VIEW
-- View sederhana dari satu tabel
CREATE VIEW vw_active_employees AS
SELECT employee_id, first_name, last_name, department
FROM employees
WHERE status = 'Active';

-- 2. COMPUTED COLUMNS VIEW
-- View dengan kalkulasi kolom
CREATE VIEW vw_employee_salaries AS
SELECT 
    employee_id,
    first_name,
    salary,
    salary * 12 as annual_salary,
    salary * 0.1 as tax_amount
FROM employees;

-- 3. JOINED VIEW
-- View yang menggabungkan beberapa tabel
CREATE VIEW vw_employee_details AS
SELECT 
    e.employee_id,
    e.first_name,
    e.last_name,
    d.department_name,
    l.location_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id
JOIN locations l ON d.location_id = l.location_id;

-- 4. AGGREGATED VIEW
-- View dengan fungsi agregasi
CREATE VIEW vw_department_summary AS
SELECT 
    department_id,
    department_name,
    COUNT(employee_id) as total_employees,
    AVG(salary) as avg_salary,
    MAX(salary) as highest_salary,
    MIN(salary) as lowest_salary
FROM employees e
JOIN departments d ON e.department_id = d.department_id
GROUP BY department_id, department_name;

-- 5. CONDITIONAL VIEW
-- View dengan logika kondisional
CREATE VIEW vw_salary_categories AS
SELECT 
    employee_id,
    first_name,
    salary,
    CASE 
        WHEN salary < 5000 THEN 'Low'
        WHEN salary BETWEEN 5000 AND 10000 THEN 'Medium'
        ELSE 'High'
    END as salary_category
FROM employees;

-- 6. SUBQUERY VIEW
-- View dengan subquery
CREATE VIEW vw_above_avg_salary AS
SELECT 
    employee_id,
    first_name,
    salary
FROM employees
WHERE salary > (
    SELECT AVG(salary) 
    FROM employees
);

-- 7. UNION VIEW
-- View yang menggabungkan hasil dari beberapa query
CREATE VIEW vw_all_contacts AS
SELECT 
    'Employee' as contact_type,
    first_name,
    last_name,
    email
FROM employees
UNION
SELECT 
    'Customer' as contact_type,
    first_name,
    last_name,
    email
FROM customers;

-- 8. FILTERED AGGREGATION VIEW
-- View dengan agregasi dan filter
CREATE VIEW vw_department_salary_stats AS
SELECT 
    d.department_name,
    COUNT(e.employee_id) as employee_count,
    AVG(CASE WHEN e.gender = 'M' THEN e.salary END) as avg_male_salary,
    AVG(CASE WHEN e.gender = 'F' THEN e.salary END) as avg_female_salary
FROM departments d
LEFT JOIN employees e ON d.department_id = e.department_id
GROUP BY d.department_name;

-- 9. COMPLEX CALCULATION VIEW
-- View dengan kalkulasi kompleks
CREATE VIEW vw_employee_performance AS
SELECT 
    e.employee_id,
    e.first_name,
    COUNT(p.project_id) as total_projects,
    SUM(p.project_value) as total_project_value,
    SUM(p.project_value) / COUNT(p.project_id) as avg_project_value,
    (e.salary / SUM(p.project_value)) * 100 as cost_percentage
FROM employees e
LEFT JOIN project_assignments pa ON e.employee_id = pa.employee_id
LEFT JOIN projects p ON pa.project_id = p.project_id
GROUP BY e.employee_id, e.first_name, e.salary;

-- 10. HIERARCHICAL VIEW
-- View untuk data hierarkis (contoh: struktur organisasi)
CREATE VIEW vw_org_structure AS
WITH RECURSIVE org_hierarchy AS (
    -- Base case: employees without managers (top level)
    SELECT 
        employee_id,
        first_name,
        manager_id,
        1 as level,
        first_name as hierarchy_path
    FROM employees
    WHERE manager_id IS NULL
    
    UNION ALL
    
    -- Recursive case: employees with managers
    SELECT 
        e.employee_id,
        e.first_name,
        e.manager_id,
        oh.level + 1,
        CONCAT(oh.hierarchy_path, ' > ', e.first_name)
    FROM employees e
    JOIN org_hierarchy oh ON e.manager_id = oh.employee_id
)
SELECT * FROM org_hierarchy;

-- 11. MATERIALIZED VIEW (PostgreSQL Syntax)
-- View yang menyimpan data fisik untuk performa query yang lebih baik
CREATE MATERIALIZED VIEW vw_sales_summary AS
SELECT 
    product_id,
    DATE_TRUNC('month', sale_date) as sale_month,
    SUM(quantity) as total_quantity,
    SUM(amount) as total_amount
FROM sales
GROUP BY product_id, DATE_TRUNC('month', sale_date)
WITH DATA;

-- Refresh materialized view
REFRESH MATERIALIZED VIEW vw_sales_summary;

-- 12. UPDATEABLE VIEW
-- View yang bisa diupdate (dengan batasan tertentu)
CREATE VIEW vw_employee_contacts AS
SELECT employee_id, first_name, last_name, email, phone
FROM employees
WHERE department_id = 1
WITH CHECK OPTION;

-- Contoh penggunaan view yang bisa diupdate
UPDATE vw_employee_contacts 
SET phone = '555-0123' 
WHERE employee_id = 1;

CREATE VIEW CustomerOrders AS
SELECT 
    c.customername,
    c.customercontact,
    c.country,
    o.orderid,
    SUM(orderamount) AS orderamount_total
FROM customers
JOIN order o ON c.orderid = o.orderid

CREATE VIEW EmployeeSales AS
SELECT 
    e.employee_name,
    SUM(saleamount) AS total_sales,
    s.salesDate
FROM employees
JOIN sales s ON 
