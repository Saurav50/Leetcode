SELECT 
    a.activity_date AS day, 
    count(distinct a.user_id) AS active_users 
FROM 
    activity a
WHERE 
    a.activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY) 
    AND a.activity_date <= '2019-07-27'
GROUP BY 
    a.activity_date;
