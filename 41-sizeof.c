#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define __u64	long long
#define __u32	int
#define __u16	short
#define __u8	char


struct in6_addr {
	char addr[16];
};


#if 1
struct	half_session1 {
	struct	half_session1	*next, *prev ;
	union{
	__u32	saddr;
	struct in6_addr ipv6_saddr;
	};
	union{
	__u32	daddr;
	struct in6_addr ipv6_daddr;
	};
	
	__u64	bytes ;
	
	__u32	hash ;
	__u32	spdb ;
	__u32	seq_diff ;
	__u32	slowpath;
	__u32	pkts ;
	
	__u16	rt_age ;
	__u16	class_id ;
	__u16	arp2;
	__u16	rt_age2;
	__u16	sport, dport ;
	__u16	arp ;

	__u8	protocol ;
	__u8	status ;
	__u8	offset ;
	__u8	vsid ;
	__u8	raw_vsid;
	__u8	ifindex;
} ;
//#else 
struct	half_session2 {
	struct	half_session2	*next, *prev ;
	__u32	hash ;
	union{
	__u32	saddr;
	struct in6_addr ipv6_saddr;
	};
	union{
	__u32	daddr;
	struct in6_addr ipv6_daddr;
	};
	__u16	sport, dport ;
	__u8	protocol ;
	__u8	status ;
	__u8	offset ;
	__u8	vsid ;
	__u32	spdb ;
#if 1 
	__u16	arp ;
	__u8	raw_vsid;  //for LOCAL_REPLY_BY_VSID
	__u8	ifindex;   // for policy route
#else
	__u32	arp ;
#endif
	__u16	rt_age ;
//	__u16	qos_id ;
//begin by sun_qiming for qos reconsitution  2020-11-21 					
	__u16	class_id ;
//end by  sun_qiming 2020-11-21 

	__u32	seq_diff ;
	__u32	slowpath;
	__u64	bytes ;
	__u32	pkts ;

#if 1	
	/*ipsec packets may reroute*/
	__u16	arp2;
	__u16	rt_age2;
#else	
	__u32	pad2[1] ;
#endif
} ;
#endif

typedef struct {
	short a;
	char b;
	float c;
}cs;

int main ()
{
    char buf[16];
    printf("sizeof(long) = %ld\n", sizeof(long));
    printf("sizeof(buf) = %ld\n", sizeof(buf));
	printf("sizeof(struct half_session1) = %ld\n", sizeof(struct half_session1));
	printf("sizeof(struct half_session2) = %ld\n", sizeof(struct half_session2));
 	printf("sizeof(struct cs) = %ld\n", sizeof(cs));
   return 0;
}
