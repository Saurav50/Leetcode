SELECT round((count(DISTINCT t.player_id)/(select count(distinct(player_id)) from activity)),2) as fraction
FROM activity t
JOIN (
    SELECT a.player_id, a.event_date
    FROM activity a
    WHERE a.event_date = (
        SELECT MIN(event_date) 
        FROM activity 
        WHERE player_id = a.player_id 
    )
) t2
ON t.player_id = t2.player_id 
AND t.event_date = DATE_ADD(t2.event_date, INTERVAL 1 DAY);
