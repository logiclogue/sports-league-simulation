let split xs =
    let length = List.length xs in
    let half = int_of_float (ceil (float_of_int length /. float_of_int 2)) in

    ListHelpers.take half xs, ListHelpers.drop half xs

let equalise (xs, ys) =
    let f = OptionHelpers.map (fun x -> x) in

    ListHelpers.complete_zip f (xs, ys)
        |> ListHelpers.unzip

let fold_f_zip_opt x_opt xs =
    match x_opt with
    | Some x -> x :: xs
    | None   -> xs

let opt_opt_to_opt (x_opt, y_opt) =
    let inner_f x y = (x, y) in
    let outer_f x = OptionHelpers.map (inner_f x) y_opt in

    OptionHelpers.bind outer_f x_opt

let zip_opt x_opts y_opts =
    ListHelpers.zip x_opts y_opts
        |> List.map opt_opt_to_opt
        |> List.fold_left fold_f_zip_opt []

let rotate xs =
    []
