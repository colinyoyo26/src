#	$OpenBSD: Makefile.inc,v 1.5 2013/06/02 19:52:36 jasper Exp $

BINDIR=		/usr/mdec

STANDALONE?=	-D_STANDALONE

.if ${MACHINE} == "loongson"
CPPFLAGS+=	${STANDALONE}
CPPFLAGS+=	-I.
CFLAGS+=	-fno-stack-protector -Wall
CFLAGS+=	-fno-builtin-vprintf -fno-builtin-printf -fno-builtin-putchar
# Silence warnings
CFLAGS+=	-fno-builtin-snprintf
CFLAGS+=	-fno-builtin-memcpy
CFLAGS+=	-fno-builtin-memcmp
CFLAGS+=	-fno-builtin-memset
CFLAGS+=	-fno-builtin-strncpy
CFLAGS+=	-fno-builtin-strncmp
CFLAGS+=	-fno-builtin-exit
CFLAGS+=	-Wa,-mfix-loongson2f-btb
SAABI=		-mips3 -mno-abicalls -G 0 -fno-pic -fno-common
AS?=		as
LD?=		ld
.endif

### Figure out what to use for libsa
LIBSADIR?=               ${.CURDIR}/../libsa

.if exists(${LIBSADIR}/${__objdir})
LIBSAOBJDIR=            ${LIBSADIR}/${__objdir}
.else
LIBSAOBJDIR=            ${LIBSADIR}
.endif

LIBSA=                  ${LIBSAOBJDIR}/libsa.a

### Figure out what to use for libz
LIBZDIR?=                ${.CURDIR}/../libz

.if exists(${LIBZDIR}/${__objdir})
LIBZOBJDIR=             ${LIBZDIR}/${__objdir}
.else
LIBZOBJDIR=             ${LIBZDIR}
.endif

LIBZ=                   ${LIBZOBJDIR}/libz.a
