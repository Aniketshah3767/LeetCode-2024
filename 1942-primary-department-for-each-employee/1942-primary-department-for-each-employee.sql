# Write your MySQL query statement below
select employee_id, department_id from employee where Primary_flag = 'Y' 
union
select employee_id, department_id
from employee
group by employee_id
having count(employee_id) = 1
order by employee_id;