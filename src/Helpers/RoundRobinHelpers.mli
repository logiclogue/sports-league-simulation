val split : 'a list -> ('a list * 'a list)
val equalise : 'a list * 'a list -> 'a option list * 'a option list
val zip_opt : 'a option list -> 'a option list -> ('a * 'a) list
val fold_f_zip_opt : 'a option -> 'a list -> 'a list
val opt_opt_to_opt : ('a option * 'b option) -> ('a * 'b) option
val rotate : 'a list -> 'a list
