#!@RCD_SCRIPTS_SHELL@
#
# $NetBSD: lighttpd.sh,v 1.1 2005/02/04 06:41:32 socrtp Exp $

# PROVIDE: lighttpd
# REQUIRE: DAEMON

. /etc/rc.subr

name="lighttpd"
rcvar=$name
command="@PREFIX@/sbin/${name}"
pidfile="/var/run/${name}.pid"
conf_file="@PKG_SYSCONFDIR@/${name}.conf"
required_files="$conf_file"
command_args="-f ${conf_file}"

load_rc_config $name
run_rc_command "$1"
