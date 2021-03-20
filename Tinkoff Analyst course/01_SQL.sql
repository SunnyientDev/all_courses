SELECT
	a.partner_rk
FROM
	msu_analytics.partner a
	inner join msu_analytics.location b
		on a.partner_rk = b.partner_rk
GROUP BY
	1
