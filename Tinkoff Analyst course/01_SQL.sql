SELECT 
	count(distinct a.partner_rk)
FROM 
	msu_analytics.legend a
	left join msu_analytics.location b
		on a.partner_rk = b.partner_rk
WHERE 
	b.location_rk is null
