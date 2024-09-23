# Write your MySQL query statement below
select ei.unique_id,e.name from employees e left join EmployeeUNI ei on e.id=ei.id;
