using System;
using System.Runtime.InteropServices;
using System.Diagnostics.Contracts;


namespace OpenVinoSharp.GenAI.Internal
{
    public static partial class NativeMethods
    {
        /// <summary>
        /// Print the error info.
        /// </summary>
        /// <param name="status">a status code.</param>
        /// <returns>error info.</returns>
        [Pure, DllImport(dllExtern, EntryPoint = "ov_genai_get_error_info",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public extern static IntPtr ov_genai_get_error_info(int status);

        /// <summary>
        /// free char
        /// </summary>
        /// <param name="content">The pointer to the char to free.</param>
        [Pure, DllImport(dllExtern, EntryPoint = "ov_genai_free",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public extern static void ov_genai_free(ref char content);


        /// <summary>
        /// Get the last error msg.
        /// </summary>
        /// <returns>The last error msg.</returns>
        [Pure, DllImport(dllExtern, EntryPoint = "ov_genai_get_last_err_msg",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public extern static IntPtr ov_genai_get_last_err_msg();
    }
}
