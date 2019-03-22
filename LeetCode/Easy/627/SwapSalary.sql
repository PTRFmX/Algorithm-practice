/* 
    Given a table salary, such as the one below, that has m=male and f=female values. 
    Swap all f and m values (i.e., change all f values to m and vice versa) with a single update query and no intermediate temp table.
    Write your MySQL query statement below
*/ 

UPDATE salary 
SET 
    sex = CASE sex
        when 'm' then 'f' 
        else 'm'
    END;