function del() {
    var len = arguments.length;
    var res = '';

    if (len === 0) {
        return res;
    }

    res += arguments[0];

    if (len === 1) {
        return res;
    } else {
       
        var index = arguments[0].indexOf(arguments[1]);
        if(index === -1){
            return res;
        }else{
          var start =   arguments[0].indexOf(arguments[1],index);
          var end =   arguments[0].indexOf('&',index);
          return res.slice(0,start) +  res.slice(end);
         
        }

       
    }

}