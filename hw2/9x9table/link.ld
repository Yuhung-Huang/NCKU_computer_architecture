_STACK_SIZE = DEFINED (_STACK_SIZE) ? _STACK_SIZE : 0x1000;


MEMORY{
 mem : ORIGIN = 0x00000000, LENGTH = 0x0000100
 mem2 : ORIGIN = 0x00000100, LENGTH = 0x0010000
}

ENTRY(_start)

SECTIONS{
/*setup.o(.text) should put in front of the *(.text), because setup.o is initiall file.We should initial first*/
  .text : {
    setup.o(.text);
    *(.text);
    *(.text.*);
  } > mem2

  .data : {
  . = ALIGN(4) ; 
  __data_paddr_start = LOADADDR(.data);
  __data_start = .;
  *(.data);
  *(.data.*);
  *(.gnu.linkonce.d.*)
  __data_end = .;
  } > mem2

  .stack : {
    . = ALIGN(4);
    _stack_end = .;
    . += _STACK_SIZE;
    _stack = .;
  } > mem2










}
