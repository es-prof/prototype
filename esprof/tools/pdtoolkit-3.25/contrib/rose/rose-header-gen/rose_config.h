/* rose_config.h.  Generated from rose_config.h.in by configure.  */
/* rose_config.h.in.  Generated from configure.in by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Major version number of backend C++ compiler. */
#define BACKEND_CXX_COMPILER_MAJOR_VERSION_NUMBER 6

/* Minor version number of backend C++ compiler. */
#define BACKEND_CXX_COMPILER_MINOR_VERSION_NUMBER 4

/* Minor version number of backend C++ compiler. */
#define BACKEND_CXX_COMPILER_PATCH_VERSION_NUMBER 1

/* Name of backend C++ compiler excluding path (used to select code generation
   options). */
#define BACKEND_CXX_COMPILER_NAME_WITHOUT_PATH "g++-6"

/* Name of backend C++ compiler including path (may or may not explicit
   include path; used to call backend). */
#define BACKEND_CXX_COMPILER_NAME_WITH_PATH "/usr/bin/g++-6"

/* Name of backend C compiler including path (may or may not explicit include
   path; used to call backend). */
#define BACKEND_C_COMPILER_NAME_WITH_PATH "/usr/bin/gcc-6"

/* Major version number of backend Fortran compiler. */
/* #undef BACKEND_FORTRAN_COMPILER_MAJOR_VERSION_NUMBER */

/* Minor version number of backend Fortran compiler. */
/* #undef BACKEND_FORTRAN_COMPILER_MINOR_VERSION_NUMBER */

/* Name of backend Fortran compiler including path (may or may not explicit
   include path; used to call backend). */
#define BACKEND_FORTRAN_COMPILER_NAME_WITH_PATH ""

/* Name of backend Java compiler including path (may or may not explicit
   include path; used to call backend). */
#define BACKEND_JAVA_COMPILER_NAME_WITH_PATH "javac"

/* Include path for backend C++ compiler. */
#define CXX_INCLUDE_STRING {"g++-6_HEADERS", "g++-6_HEADERS/hdrs", "g++-6_HEADERS/hdrs1", "g++-6_HEADERS/hdrs3", "g++-6_HEADERS/hdrs4", "g++-6_HEADERS/hdrs6", ".", "/home/liyixiao/profiler/rose-cross/build/install/include/rose", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++/x86_64-pc-linux-gnu", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++/backward", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include", "/usr/local/include", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include-fixed",  "/usr/include"}

/* Is this a GNU compiler being used to compile ROSE. */
#define CXX_IS_GNU_COMPILER 1

/* Is this an Intel compiler being used to compile ROSE. */
/* #undef CXX_IS_INTEL_COMPILER */

/* Is this the ROSE Analizer (part of tests to compile ROSE for analysis only
   using ROSE). */
/* #undef CXX_IS_ROSE_ANALYSIS */

/* Is this the ROSE AST File IO (part of tests to compile ROSE for AST File IO
   only using ROSE). */
/* #undef CXX_IS_ROSE_AST_FILE_IO */

/* Is this the ROSE Code Generator (part of tests to compile ROSE and generate
   code using ROSE). */
/* #undef CXX_IS_ROSE_CODE_GENERATION */

/* Is this the ROSE translator (part of tests to compile ROSE using ROSE). */
/* #undef CXX_IS_ROSE_TRANSLATOR */

/* -D options to hand to EDG C++ front-end. */
#define CXX_SPEC_DEF {"-D__GNUG__=6", "-D__GNUC__=6", "-D__GNUC_MINOR__=4", "-D__GNUC_PATCHLEVEL__=1", "--preinclude", "rose_edg_required_macros_and_functions.h"}

/* Include path for backend C compiler. */
#define C_INCLUDE_STRING {"gcc-6_HEADERS", "gcc-6_HEADERS/hdrs", "gcc-6_HEADERS/hdrs3", "gcc-6_HEADERS/hdrs4", "gcc-6_HEADERS/hdrs6", ".", "/home/liyixiao/profiler/rose-cross/build/install/include/rose", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++/x86_64-pc-linux-gnu", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include/c++/backward", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include", "/usr/local/include", "/usr/lib/gcc/x86_64-pc-linux-gnu/6.4.1/include-fixed",  "/usr/include"}

/* Location (unquoted) of the GCC 4.4's GOMP OpenMP runtime library. */
/* #undef GCC_GOMP_OPENMP_LIB_PATH */

/* Define to 1 if you have the `argz_append' function. */
/* #undef HAVE_ARGZ_APPEND */

/* Define to 1 if you have the `argz_create_sep' function. */
/* #undef HAVE_ARGZ_CREATE_SEP */

/* Define to 1 if you have the <argz.h> header file. */
/* #undef HAVE_ARGZ_H */

/* Define to 1 if you have the `argz_insert' function. */
/* #undef HAVE_ARGZ_INSERT */

/* Define to 1 if you have the `argz_next' function. */
/* #undef HAVE_ARGZ_NEXT */

/* Define to 1 if you have the `argz_stringify' function. */
/* #undef HAVE_ARGZ_STRINGIFY */

/* Define to 1 if you have the <assert.h> header file. */
/* #undef HAVE_ASSERT_H */

/* Define to 1 if you have the `bcopy' function. */
/* #undef HAVE_BCOPY */

/* define if the Boost library is available */
/* #undef HAVE_BOOST */

/* define if the Boost::Date_Time library is available */
/* #undef HAVE_BOOST_DATE_TIME */

/* define if the Boost::Filesystem library is available */
/* #undef HAVE_BOOST_FILESYSTEM */

/* define if the Boost::PROGRAM_OPTIONS library is available */
/* #undef HAVE_BOOST_PROGRAM_OPTIONS */

/* define if the Boost::Regex library is available */
/* #undef HAVE_BOOST_REGEX */

/* define if the Boost::System library is available */
/* #undef HAVE_BOOST_SYSTEM */

/* define if the Boost::Thread library is available */
/* #undef HAVE_BOOST_THREAD */

/* define if the Boost::Wave library is available */
/* #undef HAVE_BOOST_WAVE */

/* Define to 1 if you have the <byteswap.h> header file. */
/* #undef HAVE_BYTESWAP_H */

/* Define to 1 if you have the `closedir' function. */
/* #undef HAVE_CLOSEDIR */

/* Define to 1 if you have the <ctype.h> header file. */
/* #undef HAVE_CTYPE_H */

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_DIRENT_H */

/* Whether <dlfcn.h> and -ldl contain dladdr() */
/* #undef HAVE_DLADDR */

/* Define if you have the GNU dld library. */
/* #undef HAVE_DLD */

/* Define to 1 if you have the <dld.h> header file. */
/* #undef HAVE_DLD_H */

/* Define to 1 if you have the `dlerror' function. */
/* #undef HAVE_DLERROR */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the <dl.h> header file. */
/* #undef HAVE_DL_H */

/* Define if you have the _dyld_func_lookup function. */
/* #undef HAVE_DYLD */

/* Define to 1 if you have the <errno.h> header file. */
/* #undef HAVE_ERRNO_H */

/* Define to 1 if the system has the type `error_t'. */
/* #undef HAVE_ERROR_T */

/* Use explicit template instantiation. */
/* #undef HAVE_EXPLICIT_TEMPLATE_INSTANTIATION */

/* Define to 1 if you have the <ffi.h> header file. */
/* #undef HAVE_FFI_H */

/* Define to 1 if you have the `index' function. */
/* #undef HAVE_INDEX */

/* Define to 1 if you have the <inttypes.h> header file. */
/* #undef HAVE_INTTYPES_H */

/* Define to 1 if you have the <jni.h> header file. */
/* #undef HAVE_JNI_H */

/* Define to 1 if you have the `dl' library (-ldl). */
/* #undef HAVE_LIBDL */

/* Defined when the Yices SMT-Solver library is present and should be used. */
/* #undef HAVE_LIBYICES */

/* Define to 1 if you have the <machine/endian.h> header file. */
/* #undef HAVE_MACHINE_ENDIAN_H */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if you have the <malloc.h> header file. */
/* #undef HAVE_MALLOC_H */

/* Define to 1 if you have the `memcpy' function. */
/* #undef HAVE_MEMCPY */

/* Define to 1 if you have the `memmove' function. */
/* #undef HAVE_MEMMOVE */

/* Define to 1 if you have the <memory.h> header file. */
/* #undef HAVE_MEMORY_H */

/* Define to 1 if MySQL libraries are available */
/* #undef HAVE_MYSQL */

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the `opendir' function. */
/* #undef HAVE_OPENDIR */

/* Include OpenGL (non-glut) support. */
/* #undef HAVE_OPENGL */

/* Define if libtool can extract symbol lists from object files. */
/* #undef HAVE_PRELOADED_SYMBOLS */

/* If available, contains the Python version number currently in use. */
/* #undef HAVE_PYTHON */

/* Define to 1 if you have the `readdir' function. */
/* #undef HAVE_READDIR */

/* Define to 1 if you have the `rindex' function. */
/* #undef HAVE_RINDEX */

/* Define if you have the shl_load function. */
/* #undef HAVE_SHL_LOAD */

/* Have the SQLITE3 library */
/* #undef HAVE_SQLITE3 */

/* Define to 1 if you have the <stdint.h> header file. */
/* #undef HAVE_STDINT_H */

/* Define to 1 if you have the <stdio.h> header file. */
/* #undef HAVE_STDIO_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the `strchr' function. */
/* #undef HAVE_STRCHR */

/* Define to 1 if you have the `strcmp' function. */
/* #undef HAVE_STRCMP */

/* Define to 1 if you have the <strings.h> header file. */
/* #undef HAVE_STRINGS_H */

/* Define to 1 if you have the <string.h> header file. */
/* #undef HAVE_STRING_H */

/* Define to 1 if you have the `strrchr' function. */
/* #undef HAVE_STRRCHR */

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/dl.h> header file. */
/* #undef HAVE_SYS_DL_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
/* #undef HAVE_SYS_STAT_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Prefix path for use of IDA. */
/* #undef IDA_PRO_PATH */

/* Path to JVM executable */
/* #undef JAVA_JVM_PATH */

/* Define if the OS needs help to load dependent libraries for dlopen(). */
/* #undef LTDL_DLOPEN_DEPLIBS */

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
/* #undef LTDL_OBJDIR */

/* Define to the name of the environment variable that determines the dynamic
   library search path. */
/* #undef LTDL_SHLIBPATH_VAR */

/* Define to the extension used for shared libraries, say, ".so". */
/* #undef LTDL_SHLIB_EXT */

/* Define to the system default library search path. */
/* #undef LTDL_SYSSEARCHPATH */

/* Define if dlsym() requires a leading underscore in symbol names. */
/* #undef NEED_USCORE */

/* Location (unquoted) of the Omni OpenMP run time library. */
/* #undef OMNI_OPENMP_LIB_PATH */

/* Name of package */
#define PACKAGE "rose"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME "ROSE"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "ROSE 0.9.5a"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "rose"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.9.5a"

/* apple Operating System (OS) being used to build ROSE */
/* #undef ROSE_APPLE_OS_VENDOR */

/* Location (unquoted) of Boost specified on configure line. */
/* #undef ROSE_BOOST_PATH */

/* Build ROSE to support the Binary Analysis */
/* #undef ROSE_BUILD_BINARY_ANALYSIS_SUPPORT */

/* Build ROSE to support the CUDA langauge */
/* #undef ROSE_BUILD_CUDA_LANGUAGE_SUPPORT */

/* Build ROSE to support the C++ langauge */
/* #undef ROSE_BUILD_CXX_LANGUAGE_SUPPORT */

/* Build ROSE to support the C langauge */
/* #undef ROSE_BUILD_C_LANGUAGE_SUPPORT */

/* Build ROSE to support the Fortran langauge */
/* #undef ROSE_BUILD_FORTRAN_LANGUAGE_SUPPORT */

/* Build ROSE to support the Java langauge */
/* #undef ROSE_BUILD_JAVA_LANGUAGE_SUPPORT */

/* Build ROSE to support the OpenCL langauge */
/* #undef ROSE_BUILD_OPENCL_LANGUAGE_SUPPORT */

/* Build ROSE to support the PHP langauge */
/* #undef ROSE_BUILD_PHP_LANGUAGE_SUPPORT */

/* Build ROSE projects directory */
/* #undef ROSE_BUILD_PROJECTS_DIRECTORY_SUPPORT */

/* Build ROSE to support the Python langauge */
/* #undef ROSE_BUILD_PYTHON_LANGUAGE_SUPPORT */

/* Build ROSE tests directory */
/* #undef ROSE_BUILD_TESTS_DIRECTORY_SUPPORT */

/* Build ROSE tutorial directory */
/* #undef ROSE_BUILD_TUTORIAL_DIRECTORY_SUPPORT */

/* CentOS Operating System (OS) being used to build ROSE */
/* #undef ROSE_CENTOS_OS_VENDOR */

/* Debian Operating System (OS) being used to build ROSE */
/* #undef ROSE_DEBIAN_OS_VENDOR */

/* EDG major version number */
/* #undef ROSE_EDG_MAJOR_VERSION_NUMBER */

/* EDG minor version number */
/* #undef ROSE_EDG_MINOR_VERSION_NUMBER */

/* Location (unquoted) of the top directory path to which ROSE is installed.
   */
/* #undef ROSE_INSTALLATION_PATH */

/* OFP class path for Jave Virtual Machine */
/* #undef ROSE_OFP_CLASSPATH */

/* OFP major version number */
/* #undef ROSE_OFP_MAJOR_VERSION_NUMBER */

/* OFP minor version number */
/* #undef ROSE_OFP_MINOR_VERSION_NUMBER */

/* OFP patch version number */
/* #undef ROSE_OFP_PATCH_VERSION_NUMBER */

/* RedHat Operating System (OS) being used to build ROSE */
/* #undef ROSE_REDHAT_OS_VENDOR */

/* Variable like LD_LIBRARY_PATH */
/* #undef ROSE_SHLIBPATH_VAR */

/* Ubuntu Operating System (OS) being used to build ROSE */
/* #undef ROSE_UBUNTU_OS_VENDOR */

/* Whether to use Candl support or not within ROSE */
/* #undef ROSE_USE_CANDL */

/* Whether to use Cloog support or not within ROSE */
/* #undef ROSE_USE_CLOOG */

/* Whether to use CUDA language support or not within ROSE */
/* #undef ROSE_USE_CUDA_SUPPORT */

/* Whether to use the new EDG version 4.x */
/* #undef ROSE_USE_EDG_VERSION_4 */

/* Whether to use the new EDG version 4.3 */
/* #undef ROSE_USE_EDG_VERSION_4_3 */

/* Whether to use the new interface to EDG */
/* #undef ROSE_USE_NEW_EDG_INTERFACE */

/* Whether to use OpenCL language support or not within ROSE */
/* #undef ROSE_USE_OPENCL_SUPPORT */

/* Whether to use Parma Polyhedral Library (PPL) support or not within ROSE */
/* #undef ROSE_USE_PPL */

/* Whether to use ScopLib support or not within ROSE */
/* #undef ROSE_USE_SCOPLIB */

/* Whether to use smaller (but more numerous) generated files for the ROSE IR
   */
/* #undef ROSE_USE_SMALLER_GENERATED_FILES */

/* Support for an advanced uniform warning level for ROSE development */
/* #undef ROSE_USE_UNIFORM_ADVANCED_WARNINGS_SUPPORT */

/* Use Valgrind calls in ROSE */
/* #undef ROSE_USE_VALGRIND */

/* Whether to use the new graph IR nodes compatability option with older API
   */
/* #undef ROSE_USING_GRAPH_IR_NODES_FOR_BACKWARD_COMPATABILITY */

/* Simple preprocessor as default in ROSE */
/* #undef ROSE_WAVE_DEFAULT */

/* Location (unquoted) of Wave specified on configure line. */
/* #undef ROSE_WAVE_PATH */

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Mark that GFORTRAN is available */
/* #undef USE_GFORTRAN_IN_ROSE */

/* Link-time support for Insure. */
/* #undef USE_INSURE */

/* Support for Purify */
/* #undef USE_PURIFY */

/* Support for Purify API (Compiling with the Purify library). */
/* #undef USE_PURIFY_API */

/* Link-time support for Purify. */
/* #undef USE_PURIFY_LINKER */

/* Controls use of ROSE support for bddbddb (Binary decision diagrams (BDD)
   BDD-Based Deductive DataBase. */
/* #undef USE_ROSE_BDDBDDB_SUPPORT */

/* Controls use of BOOST WAVE support in ROSE. */
/* #undef USE_ROSE_BOOST_WAVE_SUPPORT */

/* Controls use of ROSE support for Dwarf (libdwarf) library. */
/* #undef USE_ROSE_DWARF_SUPPORT */

/* Controls if EDG Union/Struct debugging support is to be used. */
/* #undef USE_ROSE_EDG_DEBUGGING_SUPPORT */

/* Use of GCC OpenMP in ROSE. */
/* #undef USE_ROSE_GCC_OMP */

/* Controls use of ROSE support for GLUT library. */
/* #undef USE_ROSE_GLUT_SUPPORT */

/* Controls use of ROSE support for OpenMP Translator targeting GCC 4.4 's
   GOMP OpenMP RTL. */
/* #undef USE_ROSE_GOMP_OPENMP_LIBRARY */

/* Controls use of IDA support for disassembling. */
/* #undef USE_ROSE_IDA_SUPPORT */

/* Controls use of ROSE support for Intel Pin Dynamic Instrumentation Package.
   */
/* #undef USE_ROSE_INTEL_PIN_SUPPORT */

/* Controls use of ROSE support for Java. */
/* #undef USE_ROSE_INTERNAL_JAVA_SUPPORT */

/* Controls use of ROSE support for Java. */
/* #undef USE_ROSE_JAVA_SUPPORT */

/* Controls use of ROSE support for LLVM. */
/* #undef USE_ROSE_LLVM_SUPPORT */

/* Controls use of ROSE support for Maple Symbolic Algebra Package. */
/* #undef USE_ROSE_MAPLE_SUPPORT */

/* Controls use of ROSE support for OpenMP Translator targeting Omni RTL. */
/* #undef USE_ROSE_OMNI_OPENMP_SUPPORT */

/* Controls use of ROSE support for PHP. */
/* #undef USE_ROSE_PHP_SUPPORT */

/* Controls use of ROSE support for Python. */
/* #undef USE_ROSE_PYTHON_SUPPORT */

/* Controls use of ROSE support for RTED library. */
/* #undef USE_ROSE_RTED_SUPPORT */

/* Controls use of ROSE support for internal Satisfiability (SAT) Solver. */
/* #undef USE_ROSE_SAT_SUPPORT */

/* Controls use of ROSE support for SSL (libssl -- MD5) library (incompatable
   with Java, so disables Fortran support). */
/* #undef USE_ROSE_SSL_SUPPORT */

/* Controls use of ROSE support in Backstroke project for ROSS Discrete Event
   Simulator. */
/* #undef USE_ROSE_SUPPORT_BACKSTROKE_ROSS */

/* Controls use of ROSE support in Backstroke project for SPEEDES Discrete
   Event Simulator. */
/* #undef USE_ROSE_SUPPORT_BACKSTROKE_SPEEDES */

/* Wine provides access to Windows header files for analysis of windows
   applications under Linux. */
/* #undef USE_ROSE_WINDOWS_ANALYSIS_SUPPORT */

/* Version number of package */
#define VERSION "0.9.5a"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if the X Window System is missing or not being used. */
/* #undef X_DISPLAY_MISSING */

/* Absolute name of yices executable, or the empty string. */
/* #undef YICES */

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
/* #undef YYTEXT_POINTER */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to a type to use for `error_t' if it is not otherwise available. */
/* #undef error_t */
