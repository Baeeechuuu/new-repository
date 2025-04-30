-- Template dasar untuk membuat view
CREATE VIEW nama_view AS
SELECT kolom1, kolom2, kolom3
FROM nama_tabel
WHERE kondisi;

-- Template view dengan join
CREATE VIEW nama_view AS
SELECT t1.kolom1, t1.kolom2, t2.kolom1
FROM tabel1 t1
JOIN tabel2 t2 ON t1.id = t2.id
WHERE kondisi;

-- Template view dengan agregasi
CREATE VIEW nama_view AS
SELECT 
    kolom1,
    COUNT(*) as jumlah,
    SUM(kolom2) as total,
    AVG(kolom3) as rata_rata
FROM nama_tabel
GROUP BY kolom1;

-- Template view dengan subquery
CREATE VIEW nama_view AS
SELECT *
FROM nama_tabel
WHERE kolom1 IN (
    SELECT kolom1 
    FROM tabel_lain 
    WHERE kondisi
);

-- Template view dengan UNION
CREATE VIEW nama_view AS
SELECT kolom1, kolom2 FROM tabel1
UNION
SELECT kolom1, kolom2 FROM tabel2;

-- Template view dengan kondisi CASE
CREATE VIEW nama_view AS
SELECT 
    kolom1,
    CASE 
        WHEN kondisi1 THEN nilai1
        WHEN kondisi2 THEN nilai2
        ELSE nilai3
    END as kolom_hasil
FROM nama_tabel;

-- Mengganti definisi view yang sudah ada
CREATE OR REPLACE VIEW nama_view AS
SELECT kolom1, kolom2
FROM nama_tabel
WHERE kondisi;

-- Menghapus view
DROP VIEW nama_view;