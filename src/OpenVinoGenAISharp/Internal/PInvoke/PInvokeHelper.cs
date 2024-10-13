﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{

    public static class PInvokeHelper
    {
        /// <summary>
        /// Checks whether PInvoke functions can be called
        /// </summary>
        public static void TryPInvoke()
        {
            try
            {
                var size = NativeMethods.ov_genai_llm_sizeof();
            }
            catch (DllNotFoundException e)
            {
                DllImportError(e);
            }
            catch (BadImageFormatException e)
            {
                DllImportError(e);
            }
        }

        /// <summary>
        /// DllImportの際にDllNotFoundExceptionかBadImageFormatExceptionが発生した際に呼び出されるメソッド。
        /// エラーメッセージを表示して解決策をユーザに示す。
        /// </summary>
        /// <param name="ex"></param>
        public static void DllImportError(Exception ex)
        {
            throw CreateException(ex);
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="ex"></param>
        public static OVException CreateException(Exception ex)
        {
            if (ex is null)
                throw new ArgumentNullException(nameof(ex));
            return new OVException(ex.Message, ex);
        }
    }

}
