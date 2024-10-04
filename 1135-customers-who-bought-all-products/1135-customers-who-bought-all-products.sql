# Write your MySQL query statement below
SELECT c.customer_id from Customer c
join Product p
on c.product_key = p.product_key 
GROUP BY c.customer_id
Having count(Distinct p.product_key) = (select count(*) from Product)
 