# Write your MySQL query statement below
select v.customer_id, count(v.visit_id) as count_no_trans
from visits v
left join Transactions t
on v.visit_id = t.visit_id
where t.Transaction_id is null
group by v.customer_id;


-- SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans
-- FROM visits v
-- WHERE v.visit_id NOT IN (
--     SELECT t.visit_id
--     FROM Transactions t
-- )
-- GROUP BY v.customer_id;
