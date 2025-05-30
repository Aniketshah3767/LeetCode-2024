# Write your MySQL query statement below
-- select name as Employee from employee e1
-- inner join employee e2 on e1.id = e2.managerID
-- where e1.salary < e2.salary
SELECT e2.name as Employee
FROM employee e1
INNER JOIN employee e2 ON e1.id = e2.managerID
WHERE
e1.salary < e2.salary