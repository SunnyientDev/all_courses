SELECT
	count(*)
FROM
	msu_analytics.partner a
	left join msu_analytics.location b
		on a.partner_rk = b.partner_rk
WHERE
	b.partner_rk is NULL
ORDER BY
	1
