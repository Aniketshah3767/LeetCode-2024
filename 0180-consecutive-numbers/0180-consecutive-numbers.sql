# Write your MySQL query statement below
select distinct(log1.num) as ConsecutiveNums from 
    logs log1, 
    logs log4,
    logs log3
where 
    log1.id = log4.id - 1 AND
    log4.id = log3.id - 1 AND
    log1.num = log4.num AND
    log4.num = log3.num
