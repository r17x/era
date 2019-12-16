module type WasmType = {let paint: string => unit;};
/* the external is pretty stupid but it's just for demonstration purposes
   same with import("./my/path/file.js")
   in reason:
   import("./my/path/file.js")
    |> Js.Promise.then_(
        (res: (module ModuleType)) =>  {
            // define ImportedModule & assign value by dynamic import
            module ImportedModule = (val res);
            /* implement your ImportedModule */
            Js.Promise.resolve() 
        })
 */
[@bs.val] external import: string => Js.Promise.t(module WasmType) = "";

[@react.component]
let make = (~name) => {
  let (date, setDate) = React.useState(() => "Loading...");

  React.useEffect0(() => {
    let ticker =
      Js.Global.setInterval(
        () => {
          let now = Js.Date.make();
          setDate(_ => Js.Date.toString(now));
        },
        1000,
      );
    // relate with line 1 & 3
    import("../Wasm/app.js")
    |> Js.Promise.then_((res: (module WasmType)) => {
         module Y = (val res);
         Y.paint(name);
         Js.Promise.resolve();
       })
    |> ignore;

    Some(() => Js.Global.clearInterval(ticker));
  });

  <div>
    <canvas id="canvas" width="666" />
    <p> {React.string(date)} </p>
  </div>;
};
