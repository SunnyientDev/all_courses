SELECT 
	a.quest_rk, 
	abs(a.res_january - b.res_february) as result
FROM
	( -- January
		SELECT 
			quest_rk, 
			cast(sum(game_flg) as float4)/count(game_flg) as res_january
		FROM 
			msu_analytics.game
		WHERE 
			game_dttm between '2018-01-01 00:00:00' and '2018-01-31 23:59:59'
		GROUP BY 
			quest_rk
	) a inner join
	( -- February
		SELECT 
			quest_rk, 
			cast(sum(game_flg) as float4)/count(game_flg) as res_february
		FROM 
			msu_analytics.game
		WHERE 
			game_dttm between '2018-02-01 00:00:00' and '2018-02-28 23:59:59'
		GROUP BY 
			quest_rk
	) b on a.quest_rk = b.quest_rk
ORDER BY
	result desc, 
  	a.quest_rk desc
LIMIT 
	1
