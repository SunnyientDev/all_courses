SELECT 
	partner_nm, 
	avg(time) as avg_time
FROM
	(((SELECT 
	 	a.employee_rk, 
	 	time, 
	 	quest_rk
	FROM 
		msu_analytics.game a
		inner join msu_analytics.employee b
			on a.employee_rk = b.employee_rk
	WHERE 
		b.gender_cd = 'f' and a.finish_flg = 1
	) c
		inner join
	(SELECT 
		quest_rk, 
	 	location_rk
	FROM 
	 	msu_analytics.quest
	) d
			on c.quest_rk = d.quest_rk
	) e
	inner join
	(
	select location_rk, partner_rk
	from msu_analytics.location
	) f
	on e.location_rk = f.location_rk
	) g
	inner join
	(
	select partner_rk, partner_nm
	from msu_analytics.partner
	) h
	on g.partner_rk = h.partner_rk
GROUP BY 
	partner_nm
ORDER BY
	avg_time, 
	partner_nm
LIMIT 
	1
