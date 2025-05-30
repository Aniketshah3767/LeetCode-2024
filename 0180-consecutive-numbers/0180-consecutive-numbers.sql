# Write your MySQL query statement below

-- Solutiuon 1
-- select distinct(log1.num) as ConsecutiveNums from 
--     logs log1, 
--     logs log4,
--     logs log3
-- where 
--     log1.id = log4.id - 1 AND
--     log4.id = log3.id - 1 AND
--     log1.num = log4.num AND
--     log4.num = log3.num


-- Solution 2
-- select distinct num as ConsecutiveNums 
-- from (
--     select num, 
--     lead(num) over (order by id) as after,
--     lag(num) over (order by id) as b4
-- from logs
-- )
-- where
--     num = after AND num = b4


SELECT DISTINCT num AS ConsecutiveNums
FROM (
    SELECT num, 
           LEAD(num) OVER (ORDER BY id) AS after,
           LAG(num) OVER (ORDER BY id) AS b4
    FROM Logs
) AS sub
WHERE num = after AND num = b4;

