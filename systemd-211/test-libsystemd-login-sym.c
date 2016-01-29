#include <stdio.h>
#include "sd-login.h"
void* functions[] = {
sd_get_seats,
sd_get_sessions,
sd_get_uids,
sd_login_monitor_flush,
sd_login_monitor_get_fd,
sd_login_monitor_new,
sd_login_monitor_unref,
sd_pid_get_owner_uid,
sd_pid_get_session,
sd_seat_can_multi_session,
sd_seat_get_active,
sd_seat_get_sessions,
sd_session_get_seat,
sd_session_get_uid,
sd_session_is_active,
sd_uid_get_seats,
sd_uid_get_sessions,
sd_uid_get_state,
sd_uid_is_on_seat,
sd_pid_get_unit,
sd_session_get_service,
sd_session_get_type,
sd_session_get_class,
sd_session_get_display,
sd_session_get_state,
sd_seat_can_tty,
sd_seat_can_graphical,
sd_session_get_tty,
sd_login_monitor_get_events,
sd_login_monitor_get_timeout,
sd_pid_get_user_unit,
sd_pid_get_machine_name,
sd_get_machine_names,
sd_pid_get_slice,
sd_session_get_vt,
};
int main(void) {
unsigned i; for (i=0;i<sizeof(functions)/sizeof(void*);i++) printf("%p\n", functions[i]);
return 0; }