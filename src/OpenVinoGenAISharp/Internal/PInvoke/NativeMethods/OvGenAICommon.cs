﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    public partial class NativeMethods
    {
        /// <summary>
        /// Print the error info.
        /// </summary>
        /// <param name="status">a status code.</param>
        /// <returns>error info.</returns>
        [DllImport(dll_extern, EntryPoint = "ov_genai_get_error_info",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public extern static string ov_genai_get_error_info(int status);

        /// <summary>
        /// free char
        /// </summary>
        /// <param name="content">The pointer to the char to free.</param>
        [DllImport(dll_extern, EntryPoint = "ov_genai_free",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public extern static void ov_genai_free(ref char content);


        /// <summary>
        /// Get the last error msg.
        /// </summary>
        /// <returns>The last error msg.</returns>
        [DllImport(dll_extern, EntryPoint = "ov_genai_get_last_err_msg",
            CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public extern static IntPtr ov_genai_get_last_err_msg();
    }
}
