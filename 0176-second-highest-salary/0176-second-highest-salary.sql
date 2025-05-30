# Write your MySQL query statement below
-- SELECT  Name, Score,
-- RANK() OVER (ORDER BY Score DESC) AS Rank
-- FROM Students;

-- Select salary Dense_Rank() OVER (ORDER BY salary DESC()) AS desnseRank from employee

with CTE as
(SELECT salary, DENSE_RANK() OVER (ORDER BY salary DESC) AS denseRank 
FROM employee)

select max(salary) as SecondHighestSalary from CTE where denseRank = 2; 
