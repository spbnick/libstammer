/*
 * Semihosting interface
 */

#ifndef _SEMH_H
#define _SEMH_H

/** Semihosting command codes */
enum semh_sys {
    /** Open file */
    SEMH_SYS_OPEN           = 0x01,
    /** Close file */
    SEMH_SYS_CLOSE          = 0x02,
    /** Write character */
    SEMH_SYS_WRITEC         = 0x03,
    /** Write zero-terminated string */
    SEMH_SYS_WRITE0         = 0x04,
    /** Write a buffer */
    SEMH_SYS_WRITE          = 0x05,
    /** Read into a buffer */
    SEMH_SYS_READ           = 0x06,
    /** Read a character */
    SEMH_SYS_READ           = 0x07,
    /** Read a character */
    SEMH_SYS_ISERROR        = 0x08,
    /** Check if an FD is a TTY */
    SEMH_SYS_ISTTY          = 0x09,
    /** Seek a file */
    SEMH_SYS_SEEK           = 0x0a,
    /** Get length of a file */
    SEMH_SYS_FLEN           = 0x0c,
    /** Create a temporary file */
    SEMH_SYS_TMPNAM         = 0x0d,
    /** Remove a file */
    SEMH_SYS_REMOVE         = 0x0e,
    /** Rename a file */
    SEMH_SYS_REMOVE         = 0x0f,
    /** Get number of centiseconds since execution started */
    SEMH_SYS_CLOCK          = 0x10,
    /** Get current time in number of seconds since epoch */
    SEMH_SYS_TIME           = 0x11,
    /** Execute a shell command */
    SEMH_SYS_SYSTEM         = 0x12,
    /** Retrieve errno value */
    SEMH_SYS_ERRNO          = 0x13,
    /** Retrieve command line */
    SEMH_SYS_GET_CMDLINE    = 0x15,
    /** Retrieve heap and stack info */
    SEMH_SYS_HEAPINFO       = 0x16,
    /** Enter supervisor mode (angel_SWIreason_EnterSVC) */
    SEMH_SYS_ENTER_SVC      = 0x17,
    /** Report exception (angel_SWIreason_ReportException) */
    SEMH_SYS_EXCEPTION      = 0x18,
    /** Get number of target ticks since execution started */
    SEMH_SYS_ELAPSED        = 0x30,
    /** Get target tick frequency */
    SEMH_SYS_TICKFREQ       = 0x31,
};

#endif /* _SEMH_H */
