# Write your MySQL query statement below
# Write a solution to find the percentage of the users registered in each contest rounded to two decimals.
# Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.

select r.contest_id, round(count(r.user_id) * 100.0 / (select count(user_id) from Users),2) as percentage
from register r
group by r.contest_id
order by percentage desc, contest_id
