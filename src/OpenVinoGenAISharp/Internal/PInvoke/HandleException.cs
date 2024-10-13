using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    /// <summary>
    /// OpenVINO C API Return value anomaly detection handle
    /// </summary>
    static class HandleException
    {
        /// <summary>
        /// Check if there are any abnormalities in the return value, and if so, return the 
        /// corresponding exceptions according to the abnormal value
        /// </summary>
        /// <param name="status"></param>
        public static void handler(ExceptionStatus status)
        {
            if (ExceptionStatus.OK == status)
            {
                return;
            }
            else if (ExceptionStatus.GENERAL_ERROR == status)
            {
                generalError();
            }
            else if (ExceptionStatus.NOT_IMPLEMENTED == status)
            {
                notImplemented();
            }
            else if (ExceptionStatus.NETWORK_NOT_LOADED == status)
            {
                networkNotLoaded();
            }
            else if (ExceptionStatus.PARAMETER_MISMATCH == status)
            {
                parameterMismatch();
            }
            else if (ExceptionStatus.NOT_FOUND == status)
            {
                notFound();
            }
            else if (ExceptionStatus.OUT_OF_BOUNDS == status)
            {
                outOfBounds();
            }
            else if (ExceptionStatus.UNEXPECTED == status)
            {
                unExpection();
            }
            else if (ExceptionStatus.REQUEST_BUSY == status)
            {
                requestBusy();
            }
            else if (ExceptionStatus.RESULT_NOT_READY == status)
            {
                resultNotReady();
            }
            else if (ExceptionStatus.NOT_ALLOCATED == status)
            {
                notAllocated();
            }
            else if (ExceptionStatus.INFER_NOT_STARTED == status)
            {
                inferNotStarted();
            }
            else if (ExceptionStatus.NETWORK_NOT_READ == status)
            {
                networdNotRead();
            }
            else if (ExceptionStatus.INFER_CANCELLED == status)
            {
                inferCancelled();
            }
            else if (ExceptionStatus.INVALID_C_PARAM == status)
            {
                invalid_c_param();
            }
            else if (ExceptionStatus.UNKNOWN_C_ERROR == status)
            {
                unknownCError();
            }
            else if (ExceptionStatus.NOT_IMPLEMENT_C_METHOD == status)
            {
                notImplementCMethod();
            }
            else if (ExceptionStatus.UNKNOW_EXCEPTION == status)
            {
                unknownException();
            }
            else if (ExceptionStatus.PTR_NULL == status)
            {
                ptrNullException();
            }

        }
        /// <summary>
        /// Throw GENERAL_ERROR OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">general error!</exception>
        private static void generalError()
        {
            throw new OVException(ExceptionStatus.GENERAL_ERROR, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw NOT_IMPLEMENTED OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">not implemented!</exception>
        private static void notImplemented()
        {
            throw new OVException(ExceptionStatus.NOT_IMPLEMENTED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }

        /// <summary>
        /// Throw NETWORK_NOT_LOADED OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">network not loaded!</exception>
        private static void networkNotLoaded()
        {
            throw new OVException(ExceptionStatus.NETWORK_NOT_LOADED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }


        /// <summary>
        /// Throw PARAMETER_MISMATCH OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">parameter mismatch!</exception>
        private static void parameterMismatch()
        {
            throw new OVException(ExceptionStatus.PARAMETER_MISMATCH, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }

        /// <summary>
        /// Throw NOT_FOUND OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">not found!</exception>
        private static void notFound()
        {
            throw new OVException(ExceptionStatus.NOT_FOUND, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }

        /// <summary>
        /// Throw OUT_OF_BOUNDS OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">out of bounds!</exception>
        private static void outOfBounds()
        {
            throw new OVException(ExceptionStatus.OUT_OF_BOUNDS, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }


        /// <summary>
        /// Throw UNEXPECTED OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">unexpection!</exception>
        private static void unExpection()
        {
            throw new OVException(ExceptionStatus.UNEXPECTED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }



        /// <summary>
        /// Throw REQUEST_BUSY OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">request busy!</exception>
        private static void requestBusy()
        {
            throw new OVException(ExceptionStatus.REQUEST_BUSY, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw RESULT_NOT_READY OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">result not ready!</exception>
        private static void resultNotReady()
        {
            throw new OVException(ExceptionStatus.RESULT_NOT_READY, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">not allocated!</exception>
        private static void notAllocated()
        {
            throw new OVException(ExceptionStatus.NOT_ALLOCATED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw INFER_NOT_STARTED OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">infer not started!</exception>
        private static void inferNotStarted()
        {
            throw new OVException(ExceptionStatus.INFER_NOT_STARTED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw NETWORK_NOT_READ OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">netword not read!</exception>
        private static void networdNotRead()
        {
            throw new OVException(ExceptionStatus.NETWORK_NOT_READ, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw INFER_CANCELLED OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">infer cancelled!</exception>
        private static void inferCancelled()
        {
            throw new OVException(ExceptionStatus.INFER_CANCELLED, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw INVALID_C_PARAM OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">invalid c param!</exception>
        private static void invalid_c_param()
        {
            throw new OVException(ExceptionStatus.INVALID_C_PARAM, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw UNKNOWN_C_ERROR OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">unknown c error!</exception>
        private static void unknownCError()
        {
            throw new OVException(ExceptionStatus.UNKNOWN_C_ERROR, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw NOT_IMPLEMENT_C_METHOD OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">not implement c method!</exception>
        private static void notImplementCMethod()
        {
            throw new OVException(ExceptionStatus.NOT_IMPLEMENT_C_METHOD, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw UNKNOW_EXCEPTION OpenVINOException.
        /// </summary>
        /// <exception cref="OVException">unknown exception!</exception>
        private static void unknownException()
        {
            throw new OVException(ExceptionStatus.UNKNOW_EXCEPTION, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
        /// <summary>
        /// Throw PTR_NULL OpenVINOException.
        /// </summary>
        /// <exception cref="OVException"></exception>
        private static void ptrNullException()
        {
            throw new OVException(ExceptionStatus.UNKNOW_EXCEPTION, Marshal.PtrToStringAnsi(NativeMethods.ov_genai_get_last_err_msg()));
        }
    }
}
