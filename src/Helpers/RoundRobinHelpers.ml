let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    ListHelpers.take half xs, ListHelpers.drop half xs

let equalise (xs, ys) =
    let f = OptionHelpers.map (fun x -> x) in

    ListHelpers.complete_zip f (xs, ys)
        |> ListHelpers.unzip

let equalise xs =
    if List.length xs mod 2 == 1 then
        List.fold_left (fun xs x -> Some x :: xs) [None] xs
    else
        List.map (fun x -> Some x) xs

let fold_f_zip_opt xs x_opt =
    match x_opt with
    | Some x -> x :: xs
    | None   -> xs

let zip_opt x_opts y_opts =
    ListHelpers.zip x_opts y_opts
        |> OptionHelpers.fold_default []
        |> List.map OptionHelpers.opt_opt_to_opt
        |> List.fold_left fold_f_zip_opt []

let rotate xs =
    match xs with
    | x :: xs -> x :: ListHelpers.rotate xs
    | []      -> []
