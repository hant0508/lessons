set backspace=indent,eol,start
set clipboard=unnamed
set fileencodings=utf-8,windows-1251	  " подключаем кодировки
set autochdir			  " автоматически переключать рабочую папку
set mouse=a				  " включаем мышь
set autoread			  " автоматически перезагружать файл, если он был изменён
set linebreak			  " перенос по словам, а не по буквам
set noswapfile		" отключаем swap-файлы
map <Up> gk
imap <Up> <C-O>gk
map <Down> gj
imap <Down> <C-O>gj
set noerrorbells

filetype off             
filetype indent plugin on
syntax on
syntax spell toplevel
set t_Co=256
colorscheme night 
autocmd! BufRead,BufNewFile,BufEnter *.{c,cpp,h,hpp,cxx,hxx,cc,java,javascript} call CSyntaxAfter()

"syntax on
set t_Co=256
colorscheme night 
set number 
let $PATH=$MinGWpath."\\bin"
set cindent
set nomodeline
set tabstop=4
set shiftwidth=4
set showcmd
set showmode
set wildmenu
set wildignore+=*.jpg,*.bmp,*.gif,*.png,*.jpeg,*.mp3,*.mp4,*.mkv,*exe,a.out
set guicursor+=a:blinkon0
set ttyfast
set cursorline
set ruler
nnoremap ; :
set makeprg=gmake
map j gj
map k gk
map <F4> :NERDTreeToggle<CR>
map <F5> :!c++ % -o %:r.exe -lglcanvas -lgdi32 -lws2_32 -lfreeglut -lopengl32 -lglu32 && %:r.exe<CR>
set guioptions-=m  "remove menu bar
set guioptions-=T  "remove toolbar
set guioptions-=r  "remove right-hand scroll bar

if has("gui_running")
		set guifont=Consolas:h12:cRUSSIAN
endif
autocmd! BufRead,BufNewFile,BufEnter *.{c,cpp,h,hpp,cxx,hxx,cc,javascript} call CSyntaxAfter()
set nocompatible

