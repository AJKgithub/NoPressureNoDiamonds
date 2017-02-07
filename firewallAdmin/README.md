# Firewall Notes

## Linux
Add delay to packets on INTERFACE: [Source](https://superuser.com/questions/173751/how-to-deliberately-introduce-a-delay-for-incoming-udp-packets) [Source 2](http://bencane.com/2012/07/16/tc-adding-simulated-network-latency-to-your-linux-server/) [tc Man Page](http://www.lartc.org/manpages/tc.txt)
`tc qdisc add dev $INTERFACE root netem delay 250ms`

[fail2ban](https://github.com/fail2ban/fail2ban)
