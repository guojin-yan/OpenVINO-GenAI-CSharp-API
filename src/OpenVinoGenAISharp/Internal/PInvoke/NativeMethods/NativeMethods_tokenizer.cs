using System;
using System.Runtime.InteropServices;
using System.Diagnostics.Contracts;
using System.Threading.Tasks;

namespace OpenVinoSharp.GenAI.Internal
{
    public static partial class NativeMethods
    {
        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true, 
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_create")]
        public extern static ExceptionStatus ov_genai_tokenizer_create(
            [Out] IntPtr tokenizer);

        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true,
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_create_with_path")]
        public extern static ExceptionStatus ov_genai_tokenizer_create_with_path_NotWindows(
            [MarshalAs(StringUnmanagedTypeNotWindows)] string tokenizerPath,
            [Out] IntPtr tokenizer);

        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true,
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_create_with_path")]
        public extern static ExceptionStatus ov_genai_tokenizer_create_with_path_Windows(
            [MarshalAs(StringUnmanagedTypeWindows)] string tokenizerPath,
            [Out] IntPtr tokenizer);

        [Pure]
        public static ExceptionStatus ov_genai_tokenizer_create_with_path(string tokenizerPath, [Out] IntPtr tokenizer)
        {
            if (IsWindows())
                return ov_genai_tokenizer_create_with_path_Windows(tokenizerPath, tokenizer);
            return ov_genai_tokenizer_create_with_path_NotWindows(tokenizerPath, tokenizer);
        }

        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true,
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_free")]
        public extern static void ov_genai_tokenizer_free(
            IntPtr tokenizer);

        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true,
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_encode_strings")]
        public extern static ExceptionStatus ov_genai_tokenizer_encode_strings(
            IntPtr tokenizer,
            [In] StringArray prompt,
            [Out] IntPtr tokenizedInputs);


        [Pure, DllImport(dllExtern, CallingConvention = CallingConvention.Cdecl, BestFitMapping = false, ThrowOnUnmappableChar = true,
            ExactSpelling = true, EntryPoint = "ov_genai_tokenizer_encode_strings")]
        public extern static ExceptionStatus ov_genai_tokenizer_encode_strings(
            IntPtr tokenizer,
            [In] ulong[] tokens,
            ulong tokensLen,
            ref IntPtr decodeResult);

    }
}
