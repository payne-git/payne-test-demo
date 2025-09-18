#!/bin/bash


for a in access addattr_l __assert_fail bind calloc cfmakeraw cfsetispeed cfsetospeed chmod close@@GLIBC_2.17 __ctype_b_loc __ctype_tolower_loc __ctype_toupper_loc dlclose dlerror dlopen dlsym __errno_location@@GLIBC_2.17 exit fclose fcntl@@GLIBC_2.17 ferror fgetc fgets fopen fprintf fputs fread free fseek ftruncate fwrite getpid get_prefix gettimeofday gmtime inet_addr inet_addr_match inet_aton inet_ntoa inet_pton ioctl __isoc99_fscanf __isoc99_sscanf ll_index_get_tnl ll_index_to_addr ll_index_to_name ll_index_to_type ll_init_map ll_name_to_index localtime lseek@@GLIBC_2.17 malloc memcmp memcpy memset mmap open@@GLIBC_2.17 parse_rtattr pclose perror popen printf pthread_mutex_lock@@GLIBC_2.17 pthread_mutex_unlock@@GLIBC_2.17 putchar puts ra_obj_clean read@@GLIBC_2.17 realloc recvfrom@@GLIBC_2.17 remove rt_addr_n2a rtnl_close rtnl_dump_filter rtnl_listen rtnl_open rtnl_rtscope_n2a rtnl_send_check rtnl_talk rtnl_wilddump_request select sendto@@GLIBC_2.17 set_4G_led setsockopt sleep snprintf socket sprintf stderr strcasecmp strcat strchr strcmp strcpy __strdup strerror strlen strncat strncmp strncpy strrchr strsep strstr strtok strtol strtoul syscall system tcflush tcsetattr time tos_nd_default tos_ra_if_query tos_ra_update_dev tos_sys_log unlink usleep vsnprintf write@@GLIBC_2.17 __xstat 
do
    echo "#################################"
    echo $a
    grep -rn "$a" ./* | grep -v "for a in" | grep -v ";$"
    echo "#################################"
    #sleep 1
done
