using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    /// This enum contains codes for all possible return values of the interface functions
    /// </summary>
    public enum ExceptionStatus : int
    {
        /// <summary>
        /// SUCCESS!
        /// </summary>
        OK = 0,
        // map exception to C++ interface
        /// <summary>
        /// GENERAL_ERROR
        /// </summary>
        GENERAL_ERROR = -1,
        /// <summary>
        /// NOT_IMPLEMENTED
        /// </summary>
        NOT_IMPLEMENTED = -2,
        /// <summary>
        /// NETWORK_NOT_LOADED
        /// </summary>
        NETWORK_NOT_LOADED = -3,
        /// <summary>
        ///  PARAMETER_MISMATCH
        /// </summary>
        PARAMETER_MISMATCH = -4,
        /// <summary>
        /// NOT_FOUND
        /// </summary>
        NOT_FOUND = -5,
        /// <summary>
        /// OUT_OF_BOUNDS
        /// </summary>
        OUT_OF_BOUNDS = -6,

        // exception not of std::exception derived type was thrown
        /// <summary>
        /// UNEXPECTED
        /// </summary>
        UNEXPECTED = -7,
        /// <summary>
        /// REQUEST_BUSY
        /// </summary>
        REQUEST_BUSY = -8,
        /// <summary>
        /// RESULT_NOT_READY
        /// </summary>
        RESULT_NOT_READY = -9,
        /// <summary>
        /// NOT_ALLOCATED
        /// </summary>
        NOT_ALLOCATED = -10,
        /// <summary>
        /// INFER_NOT_STARTED
        /// </summary>
        INFER_NOT_STARTED = -11,
        /// <summary>
        /// NETWORK_NOT_READ
        /// </summary>
        NETWORK_NOT_READ = -12,
        /// <summary>
        /// INFER_CANCELLED
        /// </summary>
        INFER_CANCELLED = -13,

        // exception in C wrapper

        /// <summary>
        /// INVALID_C_PARAM
        /// </summary>
        INVALID_C_PARAM = -14,
        /// <summary>
        /// UNKNOWN_C_ERROR
        /// </summary>
        UNKNOWN_C_ERROR = -15,
        /// <summary>
        /// NOT_IMPLEMENT_C_METHOD
        /// </summary>
        NOT_IMPLEMENT_C_METHOD = -16,
        /// <summary>
        /// UNKNOW_EXCEPTION
        /// </summary>
        UNKNOW_EXCEPTION = -17,
        /// <summary>
        /// PTR_NULL
        /// </summary>
        PTR_NULL = -100,
    }
}
