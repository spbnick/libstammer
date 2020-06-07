/*
 * Semihosting interface
 *
 * See https://wiki.segger.com/Semihosting and
 * http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0471m/pge1358787045051.html
 */

/* Semihosting operation codes */
enum semihosting_op {
    /** Open a file on the host system */
    SEMIHOSTING_OP_SYS_OPEN         = 0x01,
    /** Close a file on the host system, opened previously by SYS_OPEN */
    SEMIHOSTING_OP_SYS_CLOSE        = 0x02,
    /* Write a character to the host terminal */
    SEMIHOSTING_OP_SYS_WRITEC       = 0x03,
    /** Write a 0-terminated string to the host terminal */
    SEMIHOSTING_OP_SYS_WRITE0       = 0x04,
    /** Write to a file on the host */
    SEMIHOSTING_OP_SYS_WRITE        = 0x05,
    /** Read from a file on the host */
    SEMIHOSTING_OP_SYS_READ         = 0x06,
    /** Read a character from the host terminal */
    SEMIHOSTING_OP_SYS_READC        = 0x07,
    /** Check if the return code from another call is an error or not */
    SEMIHOSTING_OP_SYS_ISERROR      = 0x08,
    /** Check whether a file is connected to a TTY */
    SEMIHOSTING_OP_SYS_ISTTY        = 0x09,
    /** Set the file cursor to a given position in a file */
    SEMIHOSTING_OP_SYS_SEEK         = 0x0A,
    /** Get the length of a file */
    SEMIHOSTING_OP_SYS_FLEN         = 0x0C,
    /** Get the name of a created temporary file */
    SEMIHOSTING_OP_SYS_TMPNAM       = 0x0D,
    /** Remove a file on the host system */
    SEMIHOSTING_OP_SYS_REMOVE       = 0x0E,
    /** Rename a file on the host system */
    SEMIHOSTING_OP_SYS_RENAME       = 0x0F,
    /** Return the number of centiseconds since the execution started */
    SEMIHOSTING_OP_SYS_CLOCK        = 0x10,
    /** Return the number of seconds since 00:00 January 1, 1970 */
    SEMIHOSTING_OP_SYS_TIME         = 0x11,
    /** Execute a command-line command on the host */
    SEMIHOSTING_OP_SYS_SYSTEM       = 0x12,
    /** Return the errno value from the host */
    SEMIHOSTING_OP_SYS_ERRNO        = 0x13,
    /** Get argc and argv for the application to run with */
    SEMIHOSTING_OP_SYS_GET_CMDLINE  = 0x15,
    /** Return heap and stack locations and sizes */
    SEMIHOSTING_OP_SYS_HEAPINFO     = 0x16,
    /** Return the number of TICKFREQ ticks since execution start */
    SEMIHOSTING_OP_SYS_ELAPSED      = 0x30,
    /** Return ELAPSED tick frequency */
    SEMIHOSTING_OP_SYS_TICKFREQ     = 0x31,
};

void
semihosting_write0(const char *ptr)
{
    asm(/* Operation */
        "mov r0, %0\n\t"
        /* String address */
        "mov r1, %1\n\t"
        /* Call */
        "bkpt 0xab\n\t"
        /* Output operands */
        :
        /* Input operands */
        : "i" (SEMIHOSTING_OP_SYS_WRITE0), "r" (ptr)
        /* Clobbers */
        : "r0", "r1"
    );
}
