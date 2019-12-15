
[@react.component]
let make = (~name) => {
  let (date, setDate) = React.useState(() => "Loading...");

  React.useEffect0(() => {

    let ticker = Js.Global.setInterval(() => {
      let now = Js.Date.make();
      setDate(_ => Js.Date.toString(now));
    }, 1000);

    Some(() => Js.Global.clearInterval(ticker));
  });

  <div>
    <canvas id="canvas" width="666"></canvas>
    <p>{React.string(date)}</p>
  </div>;
};
