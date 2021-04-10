#
# Regular cron jobs for the mydebian package
#
0 4	* * *	root	[ -x /usr/bin/mydebian_maintenance ] && /usr/bin/mydebian_maintenance
