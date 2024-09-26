# Write your MySQL query statement below
select s.product_id,s.year as first_year,s.quantity,s.price from sales s where (s.product_id,s.year) in (
    select product_id,min(year) from sales group by product_id
);