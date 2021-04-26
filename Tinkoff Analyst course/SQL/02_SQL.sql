SELECT 
	partner_nm, 
	avg(time) as avg_time
FROM
	(
		(
			(
				SELECT 
					game_rk.employee_rk, 
					time, 
					quest_rk
				FROM 
					msu_analytics.game game_rk
					inner join msu_analytics.employee emp_rk
						on game_rk.employee_rk = emp_rk.employee_rk
				WHERE emp_rk.gender_cd = 'f' and game_rk.finish_flg = 1
			) tim inner join 
			(
				SELECT 
					quest_rk, 
					location_rk
				FROM 
					msu_analytics.quest
			) que_rk on tim.quest_rk = que_rk.quest_rk
		) loc_rk inner join
		(
		SELECT 
			location_rk, 
			partner_rk
		FROM 
			msu_analytics.location
		) loca_rk on loc_rk.location_rk = loca_rk.location_rk
	) part_rk inner join
	(
	SELECT 
		partner_rk, 
		partner_nm
	FROM 
		msu_analytics.partner
	) parte_rk on part_rk.partner_rk = parte_rk.partner_rk
GROUP BY 
	partner_nm
ORDER BY
	avg_time, 
	partner_nm
LIMIT
	1
