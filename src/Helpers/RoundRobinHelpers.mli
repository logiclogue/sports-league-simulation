val split : 'a list -> ('a list * 'a list)
val equalise : 'a list -> 'a option list
val zip_opt : 'a option list -> 'b option list -> ('a * 'b) list
val fold_f_zip_opt : ('a * 'b) list -> ('a * 'b) option -> ('a * 'b) list
val rotate : 'a list -> 'a list
