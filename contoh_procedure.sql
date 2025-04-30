-- 1. BASIC PROCEDURE
-- Prosedur sederhana tanpa parameter
-- Digunakan untuk operasi sederhana yang tidak memerlukan input
DELIMITER //
CREATE PROCEDURE GetAllEmployees()
BEGIN
    SELECT * FROM employees;
END //
DELIMITER ;

-- Cara panggil:
CALL GetAllEmployees();

-- 2. INPUT PROCEDURE
-- Prosedur dengan parameter input
-- Digunakan ketika kita perlu memasukkan data untuk diproses
DELIMITER //
CREATE PROCEDURE GetEmployeesByDepartment(
    IN dept_name VARCHAR(50)
)
BEGIN
    SELECT * 
    FROM employees 
    WHERE department = dept_name;
END //
DELIMITER ;

-- Cara panggil:
CALL GetEmployeesByDepartment('IT');

-- 3. OUTPUT PROCEDURE
-- Prosedur yang mengembalikan nilai
-- Berguna untuk kalkulasi atau mengambil nilai spesifik
DELIMITER //
CREATE PROCEDURE CalculateTotalSalary(
    IN dept_name VARCHAR(50),
    OUT total_salary DECIMAL(10,2)
)
BEGIN
    SELECT SUM(salary) 
    INTO total_salary
    FROM employees 
    WHERE department = dept_name;
END //
DELIMITER ;

-- Cara panggil:
SET @total = 0;
CALL CalculateTotalSalary('IT', @total);
SELECT @total;

-- 4. INOUT PROCEDURE
-- Prosedur dengan parameter yang bisa digunakan untuk input dan output
-- Berguna ketika nilai parameter perlu dimodifikasi
DELIMITER //
CREATE PROCEDURE AdjustSalary(
    INOUT current_salary DECIMAL(10,2),
    IN increment_percentage INT
)
BEGIN
    SET current_salary = current_salary + 
        (current_salary * increment_percentage / 100);
END //
DELIMITER ;

-- Cara panggil:
SET @salary = 5000;
CALL AdjustSalary(@salary, 10);
SELECT @salary;

-- 5. CONDITIONAL PROCEDURE
-- Prosedur dengan logika kondisional
-- Digunakan untuk pengambilan keputusan
DELIMITER //
CREATE PROCEDURE UpdateEmployeeStatus(
    IN emp_id INT
)
BEGIN
    DECLARE years_worked INT;
    
    SELECT DATEDIFF(CURRENT_DATE, hire_date)/365
    INTO years_worked 
    FROM employees 
    WHERE id = emp_id;
    
    IF years_worked >= 5 THEN
        UPDATE employees 
        SET status = 'Senior' 
        WHERE id = emp_id;
    ELSE
        UPDATE employees 
        SET status = 'Junior' 
        WHERE id = emp_id;
    END IF;
END //
DELIMITER ;

-- 6. LOOP PROCEDURE
-- Prosedur dengan pengulangan
-- Berguna untuk pemrosesan batch atau iterasi
DELIMITER //
CREATE PROCEDURE GeneratePayslips(
    IN start_date DATE,
    IN end_date DATE
)
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE emp_id INT;
    DECLARE emp_cursor CURSOR FOR 
        SELECT id FROM employees;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN emp_cursor;
    read_loop: LOOP
        FETCH emp_cursor INTO emp_id;
        IF done THEN
            LEAVE read_loop;
        END IF;
        
        INSERT INTO payslips (employee_id, period_start, period_end)
        VALUES (emp_id, start_date, end_date);
    END LOOP;
    CLOSE emp_cursor;
END //
DELIMITER ;

-- 7. TRANSACTION PROCEDURE
-- Prosedur dengan transaksi
-- Penting untuk menjaga integritas data
DELIMITER //
CREATE PROCEDURE TransferMoney(
    IN from_account INT,
    IN to_account INT,
    IN amount DECIMAL(10,2),
    OUT success BOOLEAN
)
BEGIN
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        SET success = FALSE;
    END;
    
    START TRANSACTION;
        UPDATE accounts 
        SET balance = balance - amount 
        WHERE account_id = from_account;
        
        UPDATE accounts 
        SET balance = balance + amount 
        WHERE account_id = to_account;
    COMMIT;
    
    SET success = TRUE;
END //
DELIMITER ;

-- 8. ERROR HANDLING PROCEDURE
-- Prosedur dengan penanganan kesalahan
-- Penting untuk menangani kasus-kasus error
DELIMITER //
CREATE PROCEDURE InsertEmployeeSafely(
    IN emp_name VARCHAR(100),
    IN emp_salary DECIMAL(10,2),
    OUT error_message VARCHAR(100)
)
BEGIN
    DECLARE EXIT HANDLER FOR 1062
    BEGIN
        SET error_message = 'Duplicate employee name';
    END;
    
    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        SET error_message = 'An error occurred';
    END;
    
    INSERT INTO employees (name, salary)
    VALUES (emp_name, emp_salary);
    
    SET error_message = 'Success';
END //
DELIMITER ;


DELIMITER $$

CREATE PROCEDURE employee(
    IN employee_name VARCHAR(50),
    IN employee_id INT,
    IN employee_phone VARCHAR(80),
    IN employee_email VARCHAR(50)
)
BEGIN 
    UPDATE employees
    SET
    name = employee_name,
    phone = employee_phone,
    email = employee_email
    WHERE employeeID = employee_id
END $$

DELIMITER;

DELIMITER $$

CREATE PROCEDURE employee(
    IN employee_name VARCHAR(50),
    IN employee_id INT,
    IN employee_phone VARCHAR(80),
    IN employee_email VARCHAR(50)
)
BEGIN 
    INSERT INTO (employee_name, employee_id, employee_phone, employee_email)
    VALUES ("budi", "1", "12345", "budi@example.com")
END $$

DELIMITER ;
