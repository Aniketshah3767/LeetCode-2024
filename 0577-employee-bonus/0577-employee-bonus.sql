# Write your MySQL query statement below
select n.name, b.bonus from employee n left join bonus b on n.empid = b.empid where bonus < 1000 or bonus is null;