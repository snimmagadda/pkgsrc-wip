#!@SMF_METHOD_SHELL@
#
# $NetBSD$
#
# Init script for nats-server
#

. /lib/svc/share/smf_include.sh

PIDFILE="@NATS_HOMEDIR@/nats-server.pid"
LOGFILE="@NATS_LOGFILE@"

ulimit -n 10240

case "$1" in
start)
   	@PREFIX@/bin/nats-server -P ${PIDFILE} \
	   -l ${LOGFILE} &
	;;
stop)
	[ -f ${PIDFILE} ] && kill `@HEAD@ -1 ${PIDFILE}`
	;;
*)
	echo "Usage: $0 {start|stop}" >&2
	exit 1
	;;
esac

exit $SMF_EXIT_OK
