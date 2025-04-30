-- Template dasar stored procedure tanpa parameter
DELIMITER //
CREATE PROCEDURE nama_prosedur()
BEGIN
    SELECT * FROM nama_tabel;
END //
DELIMITER ;

-- Template dengan parameter input
DELIMITER //
CREATE PROCEDURE nama_prosedur(
    IN param1 INT,
    IN param2 VARCHAR(100)
)
BEGIN
    SELECT * 
    FROM nama_tabel
    WHERE kolom1 = param1 
    AND kolom2 = param2;
END //
DELIMITER ;

-- Template dengan parameter output
DELIMITER //
CREATE PROCEDURE nama_prosedur(
    IN param_input INT,
    OUT param_output INT
)
BEGIN
    SELECT COUNT(*) 
    INTO param_output
    FROM nama_tabel
    WHERE kolom1 = param_input;
END //
DELIMITER ;

-- Template dengan variabel lokal dan kondisi
DELIMITER //
CREATE PROCEDURE nama_prosedur(
    IN param1 INT
)
BEGIN
    DECLARE variable1 INT DEFAULT 0;
    
    IF param1 > 0 THEN
        SET variable1 = param1 * 2;
        
        SELECT * 
        FROM nama_tabel
        WHERE kolom1 = variable1;
    ELSE
        SELECT 'Parameter harus lebih besar dari 0';
    END IF;
END //
DELIMITER ;

-- Template dengan transaction
DELIMITER //
CREATE PROCEDURE nama_prosedur(
    IN param1 INT,
    IN param2 VARCHAR(100)
)
BEGIN
    DECLARE exit handler for sqlexception
    BEGIN
        ROLLBACK;
        SELECT 'Error terjadi';
    END;
    
    START TRANSACTION;
        INSERT INTO tabel1 (kolom1, kolom2) 
        VALUES (param1, param2);
        
        UPDATE tabel2 
        SET kolom1 = param1 
        WHERE kolom2 = param2;
    COMMIT;
END //
DELIMITER ;

-- Template dengan loop
DELIMITER //
CREATE PROCEDURE nama_prosedur(
    IN param1 INT
)
BEGIN
    DECLARE counter INT DEFAULT 1;
    
    WHILE counter <= param1 DO
        INSERT INTO nama_tabel (kolom1) 
        VALUES (counter);
        SET counter = counter + 1;
    END WHILE;
END //
DELIMITER ;

-- Template dengan cursor
DELIMITER //
CREATE PROCEDURE nama_prosedur()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE var1 INT;
    DECLARE var2 VARCHAR(100);
    
    DECLARE cur1 CURSOR FOR 
        SELECT kolom1, kolom2 
        FROM nama_tabel;
    
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN cur1;
    read_loop: LOOP
        FETCH cur1 INTO var1, var2;
        IF done THEN
            LEAVE read_loop;
        END IF;
        -- Proses data di sini
    END LOOP;
    CLOSE cur1;
END //
DELIMITER ;

-- Menghapus stored procedure
DROP PROCEDURE IF EXISTS nama_prosedur;

-- Memanggil stored procedure
CALL nama_prosedur(param1, param2);