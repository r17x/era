'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function Hello(Props) {
  var name = Props.name;
  var match = React.useState((function () {
          return "Loading...";
        }));
  var setDate = match[1];
  React.useEffect((function () {
          var ticker = setInterval((function (param) {
                  var now = new Date();
                  return Curry._1(setDate, (function (param) {
                                return now.toString();
                              }));
                }), 1000);
          import("../Wasm/app.js").then((function (res) {
                  Curry._1(res.paint, name);
                  return Promise.resolve(/* () */0);
                }));
          return (function (param) {
                    clearInterval(ticker);
                    return /* () */0;
                  });
        }), ([]));
  return React.createElement("div", undefined, React.createElement("canvas", {
                  id: "canvas",
                  width: "666"
                }), React.createElement("p", undefined, match[0]));
}

var make = Hello;

exports.make = make;
/* react Not a pure module */
