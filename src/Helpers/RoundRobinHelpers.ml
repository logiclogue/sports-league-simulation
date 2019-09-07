let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    ListHelpers.take half xs, ListHelpers.drop half xs

let equalise (xs, ys) =
    let f = OptionHelpers.map (fun x -> x) in

    ListHelpers.complete_zip f (xs, ys)
        |> ListHelpers.unzip

let fold_f_zip_opt xs x_opt =
    match x_opt with
    | Some x -> x :: xs
    | None   -> xs

let opt_opt_to_opt (x_opt, y_opt) =
    let inner_f x y = (x, y) in
    let outer_f x = OptionHelpers.map (inner_f x) y_opt in

    OptionHelpers.bind outer_f x_opt

let zip_opt x_opts y_opts =
    ListHelpers.zip x_opts y_opts
        |> OptionHelpers.fold_default []
        |> List.map opt_opt_to_opt
        |> List.fold_left fold_f_zip_opt []

(*
zip_opt                  : 'a option list -> 'b option list -> ('a * 'a) list
ListHelpers.zip          : 'a option list -> 'b option list -> ('a option * 'b option) list option
ListHelpers.fold_default : ('a option * 'b option) list -> ('a option * 'b option) list option -> ('a option * 'b option) list
List.map                 : (('a option * 'b option) -> ('a * 'b) option) -> ('a option * 'b option) list -> ('a * 'b) option list
List.fold_left           : (('a * 'b) list -> ('a * 'b) option -> ('a * 'b) list) -> ('a * 'b) list -> ('a * 'b) option list -> ('a * 'b) list
*)

let true_rotate xs =
    match xs with
    | x :: xs -> List.append xs [x]
    | []      -> []

let rotate xs =
    match xs with
    | x :: xs -> x :: true_rotate xs
    | []      -> []
