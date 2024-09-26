# Write your MySQL query statement below
select p.product_id,IFNULL(round(sum(u.units*p.price)/sum(u.units),2),0) as average_price from prices p left join unitssold u on p.product_id=u.product_id
AND u.purchase_date >= p.start_date 
AND u.purchase_date <= p.end_date group by product_id ;