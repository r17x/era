'use strict'

var Curry = require('bs-platform/lib/js/curry.js')
var React = require('react')

function Hello(Props) {
  Props.name
  var match = React.useState(function() {
    return 'Loading...'
  })
  var setDate = match[1]
  // FIXME: THIS IS NAIVE SOLUTION USING ONE-WAY BINDING
  import('../Wasm/app')
    .then(wasm => wasm.paint('hello world'))
    .catch(console.error)
  React.useEffect(function() {
    var ticker = setInterval(function(param) {
      var now = new Date()
      return Curry._1(setDate, function(param) {
        return now.toString()
      })
    }, 1000)
    return function(param) {
      clearInterval(ticker)
      return /* () */ 0
    }
  }, [])
  return React.createElement(
    'div',
    undefined,
    React.createElement('canvas', {
      id: 'canvas',
      width: '666'
    }),
    React.createElement('p', undefined, match[0])
  )
}

var make = Hello

exports.make = make
/* react Not a pure module */
