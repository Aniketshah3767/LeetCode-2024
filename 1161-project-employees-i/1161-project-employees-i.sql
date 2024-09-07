# Write your MySQL query statement below
-- Write an SQL query that reports the average experience years 
-- of all the employees for each project, rounded to 2 digits.
select 
    p.project_id, 
    round(avg(experience_years),2) as average_years
from 
    project p
join 
    employee e
    on p.employee_id = e.employee_id
GROUP BY 
    p.project_id;

