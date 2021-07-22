# 接口说明<a name="ZH-CN_TOPIC_0000001120353442"></a>

-   [type\_define.h](#section1595216182453)
-   [model\_config.h](#section19261840125219)
-   [feature\_interpreter.h](#section7405193574410)
-   [model\_interpreter.h](#section18190171223412)

## type\_define.h<a name="section1595216182453"></a>

type\_define.h中定义了DLLite-micro组件中涉及的返回码，根据返回码的内容可以对照了解异常的内容。

**表 1**  type\_define中定义的常量

<a name="table7392152410175"></a>
<table><thead align="left"><tr id="row439382471716"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p83937243171"><a name="p83937243171"></a><a name="p83937243171"></a>常量名称</p>
</th>
<th class="cellrowborder" valign="top" width="26.222622262226224%" id="mcps1.2.4.1.2"><p id="p1739352415177"><a name="p1739352415177"></a><a name="p1739352415177"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="40.44404440444045%" id="mcps1.2.4.1.3"><p id="p439332418178"><a name="p439332418178"></a><a name="p439332418178"></a>常量值</p>
</th>
</tr>
</thead>
<tbody><tr id="row639372418174"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p2393024191719"><a name="p2393024191719"></a><a name="p2393024191719"></a>ReturnCode</p>
</td>
<td class="cellrowborder" valign="top" width="26.222622262226224%" headers="mcps1.2.4.1.2 "><p id="p14393132451714"><a name="p14393132451714"></a><a name="p14393132451714"></a>接口运行结果返回值</p>
</td>
<td class="cellrowborder" valign="top" width="40.44404440444045%" headers="mcps1.2.4.1.3 "><p id="p177161035172717"><a name="p177161035172717"></a><a name="p177161035172717"></a>SUCCESS: 运行成功</p>
<p id="p3716193518271"><a name="p3716193518271"></a><a name="p3716193518271"></a>UNKNOWN: 未知错误发生</p>
<p id="p258019487200"><a name="p258019487200"></a><a name="p258019487200"></a>INVALID_PARAM:<strong id="b8715492376"><a name="b8715492376"></a><a name="b8715492376"></a> </strong>参数错误</p>
<p id="p145805487201"><a name="p145805487201"></a><a name="p145805487201"></a>INVALID_POINTER:<strong id="b1664517138372"><a name="b1664517138372"></a><a name="b1664517138372"></a> </strong>无效指针</p>
<p id="p0580174822015"><a name="p0580174822015"></a><a name="p0580174822015"></a>REGISTER_REPEATED:<strong id="b3553201718377"><a name="b3553201718377"></a><a name="b3553201718377"></a> </strong>重复注册</p>
<p id="p15580164818201"><a name="p15580164818201"></a><a name="p15580164818201"></a>REGISTER_EXCEED_NUM_LIMIT:<strong id="b177921522203713"><a name="b177921522203713"></a><a name="b177921522203713"></a> </strong>特性注册次数超出限制</p>
<p id="p758016480208"><a name="p758016480208"></a><a name="p758016480208"></a>UNREGISTER_WITH_TASK: 任务未注销</p>
<p id="p1358054812015"><a name="p1358054812015"></a><a name="p1358054812015"></a>DESTROY_WITH_TASK:<strong id="b76341434103718"><a name="b76341434103718"></a><a name="b76341434103718"></a> </strong>销毁模型推理实例时，仍有任务正在运行，无法释放资源</p>
<p id="p1471619359273"><a name="p1471619359273"></a><a name="p1471619359273"></a>LOAD_EXCEED_NUM_LIMIT: 超出最大数量限制</p>
<p id="p371619357278"><a name="p371619357278"></a><a name="p371619357278"></a>LOAD_EXCEED_MEM_LIMIT: 超出内存限制</p>
<p id="p14716133522711"><a name="p14716133522711"></a><a name="p14716133522711"></a>LOAD_REPEATED: 重复加载</p>
<p id="p1571683572717"><a name="p1571683572717"></a><a name="p1571683572717"></a>LOAD_NOT_EXECUTED: 加载错误</p>
<p id="p177161935152711"><a name="p177161935152711"></a><a name="p177161935152711"></a>UNLOAD_MODEL_NOT_EXIST: 所指定卸载的模型不存在</p>
<p id="p1571633516272"><a name="p1571633516272"></a><a name="p1571633516272"></a>UNLOAD_MODEL_WITH_TASK: 卸载正在推理的模型</p>
<p id="p971643514277"><a name="p971643514277"></a><a name="p971643514277"></a>UNLOAD_REPEATED: 模型重复卸载</p>
<p id="p1871614357275"><a name="p1871614357275"></a><a name="p1871614357275"></a>UNLOAD_HAS_EXECUTED: 已经执行模型卸载</p>
<p id="p107161635162714"><a name="p107161635162714"></a><a name="p107161635162714"></a>INVOKE_NOT_EXISTED_MODEL: 推理的模型不存在</p>
<p id="p6716153522710"><a name="p6716153522710"></a><a name="p6716153522710"></a>INVOKE_TENSOR_NOT_MATCH: 输入的Tensor不符合模型要求</p>
<p id="p1071653516276"><a name="p1071653516276"></a><a name="p1071653516276"></a>UNSUPPORTED_API: 当前版本不支持的接口</p>
<p id="p1071619509512"><a name="p1071619509512"></a><a name="p1071619509512"></a>SERVER_BINDER_NOT_INIT: 任务调度服务Binder未初始化（预留返回值，暂未使用）</p>
<p id="p177162035182719"><a name="p177162035182719"></a><a name="p177162035182719"></a>EMPTY_RESOURCE:<strong id="b16441351173813"><a name="b16441351173813"></a><a name="b16441351173813"></a> </strong>资源空缺</p>
<p id="p671663518278"><a name="p671663518278"></a><a name="p671663518278"></a>INVALID_MODEL_FILE: 模型文件错误</p>
<p id="p771683510275"><a name="p771683510275"></a><a name="p771683510275"></a>FAILED_TO_GET_RESOURCE: 资源获取错误</p>
</td>
</tr>
</tbody>
</table>

## model\_config.h<a name="section19261840125219"></a>

**表 2**  model\_config中定义的结构

<a name="table334812159422"></a>
<table><thead align="left"><tr id="row17348151544210"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p11227153614317"><a name="p11227153614317"></a><a name="p11227153614317"></a>结构体名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p14227936104313"><a name="p14227936104313"></a><a name="p14227936104313"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p12271536114314"><a name="p12271536114314"></a><a name="p12271536114314"></a>属性</p>
</th>
</tr>
</thead>
<tbody><tr id="row172714554719"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1228114512474"><a name="p1228114512474"></a><a name="p1228114512474"></a>IOTensor</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p102812459474"><a name="p102812459474"></a><a name="p102812459474"></a>IOTensor用于存储AI推理框架输入输出的数据。DLLite-micro接收用户传入的数据，以IOTensor的类型透传给底层推理框架进行推理，推理结果同样以IOTensor类型进行输出。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6522712481"><a name="p6522712481"></a><a name="p6522712481"></a>string name:<strong id="b160491213409"><a name="b160491213409"></a><a name="b160491213409"></a> </strong>tensor名称</p>
<p id="p7522211485"><a name="p7522211485"></a><a name="p7522211485"></a>TensorType type: tensor类型</p>
<p id="p1152215124815"><a name="p1152215124815"></a><a name="p1152215124815"></a>TensorLayout layout: tensor排布</p>
<p id="p19522141174819"><a name="p19522141174819"></a><a name="p19522141174819"></a>std::vector&lt;size_t&gt; shape: tensor各维度大小</p>
<p id="p1522131144818"><a name="p1522131144818"></a><a name="p1522131144818"></a>std::pair&lt;void*, size_t&gt; buffer: &lt;数据，占用大小&gt;</p>
</td>
</tr>
</tbody>
</table>

**表 3**  TensorType  tensor数据类别枚举值

<a name="table972098154915"></a>
<table><thead align="left"><tr id="row197201082493"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p177201587490"><a name="p177201587490"></a><a name="p177201587490"></a>定义</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p107201483493"><a name="p107201483493"></a><a name="p107201483493"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p167201688493"><a name="p167201688493"></a><a name="p167201688493"></a>含义</p>
</th>
</tr>
</thead>
<tbody><tr id="row157200817491"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p73921212135013"><a name="p73921212135013"></a><a name="p73921212135013"></a>UINT8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p73921121509"><a name="p73921121509"></a><a name="p73921121509"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9392111219507"><a name="p9392111219507"></a><a name="p9392111219507"></a>8位无符号整型</p>
</td>
</tr>
<tr id="row572111854918"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p107221642105013"><a name="p107221642105013"></a><a name="p107221642105013"></a>INT8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p8722242125020"><a name="p8722242125020"></a><a name="p8722242125020"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19722104215500"><a name="p19722104215500"></a><a name="p19722104215500"></a>8位有符号整型</p>
</td>
</tr>
<tr id="row972114854912"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p47221642185012"><a name="p47221642185012"></a><a name="p47221642185012"></a>INT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1572284215500"><a name="p1572284215500"></a><a name="p1572284215500"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1172320426507"><a name="p1172320426507"></a><a name="p1172320426507"></a>16位有符号整型</p>
</td>
</tr>
<tr id="row17212834910"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p16723134210507"><a name="p16723134210507"></a><a name="p16723134210507"></a>UINT32</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p9723142145016"><a name="p9723142145016"></a><a name="p9723142145016"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p8723942165012"><a name="p8723942165012"></a><a name="p8723942165012"></a>32位无符号整型</p>
</td>
</tr>
<tr id="row27212816495"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p97239423504"><a name="p97239423504"></a><a name="p97239423504"></a>INT32</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p177231942105015"><a name="p177231942105015"></a><a name="p177231942105015"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p167231942145013"><a name="p167231942145013"></a><a name="p167231942145013"></a>32位有符号整型</p>
</td>
</tr>
<tr id="row127211287496"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15723742195017"><a name="p15723742195017"></a><a name="p15723742195017"></a>FLOAT</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p177231342195010"><a name="p177231342195010"></a><a name="p177231342195010"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1172324218503"><a name="p1172324218503"></a><a name="p1172324218503"></a>单精度浮点型</p>
</td>
</tr>
<tr id="row3721128104915"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p18221959175010"><a name="p18221959175010"></a><a name="p18221959175010"></a>FLOAT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1622116598503"><a name="p1622116598503"></a><a name="p1622116598503"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11221185915015"><a name="p11221185915015"></a><a name="p11221185915015"></a>半精度浮点型</p>
</td>
</tr>
<tr id="row164519182522"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p77061434155214"><a name="p77061434155214"></a><a name="p77061434155214"></a>INT64</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p7706173465219"><a name="p7706173465219"></a><a name="p7706173465219"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p870713342522"><a name="p870713342522"></a><a name="p870713342522"></a>64位有符号整型</p>
</td>
</tr>
<tr id="row18719821155214"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1970723419521"><a name="p1970723419521"></a><a name="p1970723419521"></a>UINT16</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1870753415216"><a name="p1870753415216"></a><a name="p1870753415216"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19707193419524"><a name="p19707193419524"></a><a name="p19707193419524"></a>16位无符号整型</p>
</td>
</tr>
</tbody>
</table>

**表 4**  TensorLayout  tensor排布枚举值

<a name="table657025435313"></a>
<table><thead align="left"><tr id="row165703547531"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p526619225410"><a name="p526619225410"></a><a name="p526619225410"></a>定义</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1426611255419"><a name="p1426611255419"></a><a name="p1426611255419"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p102673219546"><a name="p102673219546"></a><a name="p102673219546"></a>含义</p>
</th>
</tr>
</thead>
<tbody><tr id="row1957085415533"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p11570195455311"><a name="p11570195455311"></a><a name="p11570195455311"></a>NONE</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p13570145485315"><a name="p13570145485315"></a><a name="p13570145485315"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p10570754165311"><a name="p10570754165311"></a><a name="p10570754165311"></a>无数据排布</p>
</td>
</tr>
<tr id="row557085415319"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1457015455319"><a name="p1457015455319"></a><a name="p1457015455319"></a>NCHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p15701854175319"><a name="p15701854175319"></a><a name="p15701854175319"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p457015425311"><a name="p457015425311"></a><a name="p457015425311"></a>NCHW数据排布</p>
</td>
</tr>
<tr id="row2057035416538"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p155701654105317"><a name="p155701654105317"></a><a name="p155701654105317"></a>NHWC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p8570454165311"><a name="p8570454165311"></a><a name="p8570454165311"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p175701354105310"><a name="p175701354105310"></a><a name="p175701354105310"></a>NHWC数据排布</p>
</td>
</tr>
<tr id="row1757015485313"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p257075425310"><a name="p257075425310"></a><a name="p257075425310"></a>HWKC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p157055405318"><a name="p157055405318"></a><a name="p157055405318"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5571155415534"><a name="p5571155415534"></a><a name="p5571155415534"></a>HWKC数据排布</p>
</td>
</tr>
<tr id="row1971023214"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1481423512"><a name="p1481423512"></a><a name="p1481423512"></a>HWCK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p98112318112"><a name="p98112318112"></a><a name="p98112318112"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p18811231419"><a name="p18811231419"></a><a name="p18811231419"></a>HWCK数据排布</p>
</td>
</tr>
<tr id="row145711554125314"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4571205475318"><a name="p4571205475318"></a><a name="p4571205475318"></a>KCHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p857113541536"><a name="p857113541536"></a><a name="p857113541536"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p37941473510"><a name="p37941473510"></a><a name="p37941473510"></a>KCHW数据排布</p>
</td>
</tr>
<tr id="row11571195418533"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p165712549536"><a name="p165712549536"></a><a name="p165712549536"></a>CKHW</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1857195435314"><a name="p1857195435314"></a><a name="p1857195435314"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187947479518"><a name="p187947479518"></a><a name="p187947479518"></a>CKHW数据排布</p>
</td>
</tr>
<tr id="row15712054145314"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1857195413536"><a name="p1857195413536"></a><a name="p1857195413536"></a>KHWC</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p657105419539"><a name="p657105419539"></a><a name="p657105419539"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187949471159"><a name="p187949471159"></a><a name="p187949471159"></a>KHWC数据排布</p>
</td>
</tr>
<tr id="row357115455315"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p8571954115314"><a name="p8571954115314"></a><a name="p8571954115314"></a>CHWK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1557195418533"><a name="p1557195418533"></a><a name="p1557195418533"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11794134719510"><a name="p11794134719510"></a><a name="p11794134719510"></a>CHWK数据排布</p>
</td>
</tr>
<tr id="row105711154175318"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1157115455319"><a name="p1157115455319"></a><a name="p1157115455319"></a>NC4HW4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p11571135412539"><a name="p11571135412539"></a><a name="p11571135412539"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1079454717515"><a name="p1079454717515"></a><a name="p1079454717515"></a>NC4HW4数据排布</p>
</td>
</tr>
<tr id="row135712054175318"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p857113547538"><a name="p857113547538"></a><a name="p857113547538"></a>NCHWC8</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p19571054185315"><a name="p19571054185315"></a><a name="p19571054185315"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1794647552"><a name="p1794647552"></a><a name="p1794647552"></a>NCHWC8数据排布</p>
</td>
</tr>
<tr id="row657145419535"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p9571125425313"><a name="p9571125425313"></a><a name="p9571125425313"></a>ROW_MAJOR</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p45719543531"><a name="p45719543531"></a><a name="p45719543531"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p187941479513"><a name="p187941479513"></a><a name="p187941479513"></a>行优先排布</p>
</td>
</tr>
<tr id="row957110548539"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p257195418533"><a name="p257195418533"></a><a name="p257195418533"></a>LSTM_MTK</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10572854155310"><a name="p10572854155310"></a><a name="p10572854155310"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p12794124717519"><a name="p12794124717519"></a><a name="p12794124717519"></a>LSTM_MTK数据排布</p>
</td>
</tr>
</tbody>
</table>

**表 5**  InferFrameworkType  底层推理框架类型枚举值

<a name="table4323105618496"></a>
<table><thead align="left"><tr id="row1632375684919"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p6754182512121"><a name="p6754182512121"></a><a name="p6754182512121"></a>定义</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p14754152551214"><a name="p14754152551214"></a><a name="p14754152551214"></a>值</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p47541625141215"><a name="p47541625141215"></a><a name="p47541625141215"></a>含义</p>
</th>
</tr>
</thead>
<tbody><tr id="row182112454514"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p202111145195114"><a name="p202111145195114"></a><a name="p202111145195114"></a>INFER</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p192111545155114"><a name="p192111545155114"></a><a name="p192111545155114"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1415144218410"><a name="p1415144218410"></a><a name="p1415144218410"></a>默认初始化的非法值</p>
</td>
</tr>
<tr id="row1731544877"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p14731144417717"><a name="p14731144417717"></a><a name="p14731144417717"></a>MINDSPORE</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p07311844178"><a name="p07311844178"></a><a name="p07311844178"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p973154412716"><a name="p973154412716"></a><a name="p973154412716"></a>Mindspore推理框架</p>
</td>
</tr>
</tbody>
</table>

**表 6**  ModelConfig公有变量

<a name="table1111012202717"></a>
<table><thead align="left"><tr id="row7110162014712"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1111052014711"><a name="p1111052014711"></a><a name="p1111052014711"></a>变量名</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p101115205720"><a name="p101115205720"></a><a name="p101115205720"></a>变量解释</p>
</th>
</tr>
</thead>
<tbody><tr id="row1211132020710"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p811152013719"><a name="p811152013719"></a><a name="p811152013719"></a>std::string modelName_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1311162013712"><a name="p1311162013712"></a><a name="p1311162013712"></a>模型名称。</p>
</td>
</tr>
<tr id="row347515161785"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14752160813"><a name="p14752160813"></a><a name="p14752160813"></a>std::string modelPath_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1547516161281"><a name="p1547516161281"></a><a name="p1547516161281"></a>模型结构文件路径。</p>
</td>
</tr>
<tr id="row4444181815815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p20444171811816"><a name="p20444171811816"></a><a name="p20444171811816"></a>std::string weightPath_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1144411181082"><a name="p1144411181082"></a><a name="p1144411181082"></a>模型权重文件路径。weightSeparateFlag_为true时，需要单独提供模型权重文件；weightSeparateFlag_为false，此项为空。</p>
</td>
</tr>
<tr id="row7352122018814"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1635362013814"><a name="p1635362013814"></a><a name="p1635362013814"></a>bool weightSeparateFlag_</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1735322016817"><a name="p1735322016817"></a><a name="p1735322016817"></a>权重分离标识。在ARM32A架构平台，DLLite-micro采用模型结构和权重分离的形式保存模型；在ARM32M架构平台，权重不分离存储。默认值为true。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  ModelConfig类接口

<a name="table115596115214"></a>
<table><thead align="left"><tr id="row1115515619529"><th class="cellrowborder" valign="top" width="33.650000000000006%" id="mcps1.2.4.1.1"><p id="p039207115320"><a name="p039207115320"></a><a name="p039207115320"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="36.39%" id="mcps1.2.4.1.2"><p id="p039137115318"><a name="p039137115318"></a><a name="p039137115318"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="29.959999999999997%" id="mcps1.2.4.1.3"><p id="p23957195315"><a name="p23957195315"></a><a name="p23957195315"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row141559612525"><td class="cellrowborder" valign="top" width="33.650000000000006%" headers="mcps1.2.4.1.1 "><p id="p7911534165312"><a name="p7911534165312"></a><a name="p7911534165312"></a>ReturnCode CheckModelConfig() const</p>
</td>
<td class="cellrowborder" valign="top" width="36.39%" headers="mcps1.2.4.1.2 "><p id="p1019015365316"><a name="p1019015365316"></a><a name="p1019015365316"></a>检查模型配置文件</p>
<p id="p16612190185515"><a name="p16612190185515"></a><a name="p16612190185515"></a><strong id="b37591055551"><a name="b37591055551"></a><a name="b37591055551"></a>返回值：</strong></p>
<p id="p55361167559"><a name="p55361167559"></a><a name="p55361167559"></a>SUCCESS    模型配置文件检查成功</p>
<p id="p1843473717554"><a name="p1843473717554"></a><a name="p1843473717554"></a>INVALID_PARAM    无效的推理模型参数</p>
<p id="p6467945175510"><a name="p6467945175510"></a><a name="p6467945175510"></a>EMPTY_RESOURCE  模型配置文件为空</p>
<p id="p51597526559"><a name="p51597526559"></a><a name="p51597526559"></a>INVALID_MODEL_FILE    无效的模型配置文件</p>
</td>
<td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.2.4.1.3 "><p id="p1524712398529"><a name="p1524712398529"></a><a name="p1524712398529"></a>NA</p>
</td>
</tr>
</tbody>
</table>

## feature\_interpreter.h<a name="section7405193574410"></a>

**表 8**  feature\_interpreter定义的结构体

<a name="table163712681117"></a>
<table><thead align="left"><tr id="row186371926131113"><th class="cellrowborder" valign="top" width="33.2%" id="mcps1.2.4.1.1"><p id="p46384267115"><a name="p46384267115"></a><a name="p46384267115"></a>结构体名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.300000000000004%" id="mcps1.2.4.1.2"><p id="p10638726101115"><a name="p10638726101115"></a><a name="p10638726101115"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="33.5%" id="mcps1.2.4.1.3"><p id="p17821155511148"><a name="p17821155511148"></a><a name="p17821155511148"></a>属性</p>
</th>
</tr>
</thead>
<tbody><tr id="row26381426151117"><td class="cellrowborder" valign="top" width="33.2%" headers="mcps1.2.4.1.1 "><p id="p1638182661112"><a name="p1638182661112"></a><a name="p1638182661112"></a>VersionInfo</p>
</td>
<td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.2.4.1.2 "><p id="p3638122614112"><a name="p3638122614112"></a><a name="p3638122614112"></a>版本信息</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p68751646131519"><a name="p68751646131519"></a><a name="p68751646131519"></a>string version: DLLite-Micro版本号</p>
<p id="p20875046171512"><a name="p20875046171512"></a><a name="p20875046171512"></a>vector&lt;string&gt; frameworkInfos: 推理框架列表</p>
</td>
</tr>
<tr id="row066105141715"><td class="cellrowborder" valign="top" width="33.2%" headers="mcps1.2.4.1.1 "><p id="p14661151171"><a name="p14661151171"></a><a name="p14661151171"></a>FrameworkInfo</p>
</td>
<td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.2.4.1.2 "><p id="p46605101710"><a name="p46605101710"></a><a name="p46605101710"></a>框架信息</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p1852318296422"><a name="p1852318296422"></a><a name="p1852318296422"></a>string version: 推理框架版本号</p>
<p id="p5523329184220"><a name="p5523329184220"></a><a name="p5523329184220"></a>string option: 预留字段，不使用时为空串</p>
</td>
</tr>
<tr id="row42591227220"><td class="cellrowborder" valign="top" width="33.2%" headers="mcps1.2.4.1.1 "><p id="p1125902215210"><a name="p1125902215210"></a><a name="p1125902215210"></a>FeatureConfig</p>
</td>
<td class="cellrowborder" valign="top" width="33.300000000000004%" headers="mcps1.2.4.1.2 "><p id="p526017226219"><a name="p526017226219"></a><a name="p526017226219"></a>特性配置信息，featureName不可重复</p>
</td>
<td class="cellrowborder" valign="top" width="33.5%" headers="mcps1.2.4.1.3 "><p id="p192602224219"><a name="p192602224219"></a><a name="p192602224219"></a>string featureName: 特性名称（必选）</p>
</td>
</tr>
</tbody>
</table>

**表 9**  FeatureInterpreter类提供的接口

<a name="table1746717205576"></a>
<table><thead align="left"><tr id="row646812010576"><th class="cellrowborder" valign="top" width="34.870000000000005%" id="mcps1.2.4.1.1"><p id="p187731595918"><a name="p187731595918"></a><a name="p187731595918"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="35.949999999999996%" id="mcps1.2.4.1.2"><p id="p1177375135917"><a name="p1177375135917"></a><a name="p1177375135917"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="29.18%" id="mcps1.2.4.1.3"><p id="p17731959592"><a name="p17731959592"></a><a name="p17731959592"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1452155711715"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p1979843151814"><a name="p1979843151814"></a><a name="p1979843151814"></a>static ReturnCode <strong id="b2079843141813"><a name="b2079843141813"></a><a name="b2079843141813"></a>GetVersion</strong>(VersionInfo&amp; versionInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p5798836184"><a name="p5798836184"></a><a name="p5798836184"></a>获取版本信息</p>
<p id="p0798153171817"><a name="p0798153171817"></a><a name="p0798153171817"></a><strong id="b079833111814"><a name="b079833111814"></a><a name="b079833111814"></a>返回值：</strong></p>
<p id="p127983381812"><a name="p127983381812"></a><a name="p127983381812"></a>SUCCESS  获取版本信息成功</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p17799136182"><a name="p17799136182"></a><a name="p17799136182"></a>VersionInfo&amp; versionInfo: 版本信息</p>
</td>
</tr>
<tr id="row3344102513237"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p33441425112311"><a name="p33441425112311"></a><a name="p33441425112311"></a>static std::vector&lt;std::string&gt;<strong id="b11541130142315"><a name="b11541130142315"></a><a name="b11541130142315"></a>GetFeatureNameList</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p1934412517234"><a name="p1934412517234"></a><a name="p1934412517234"></a>获取所有已注册的特征实例命名的名称列表</p>
<p id="p1546417394235"><a name="p1546417394235"></a><a name="p1546417394235"></a><strong id="b123891717103115"><a name="b123891717103115"></a><a name="b123891717103115"></a>返回值：</strong>特征实例命名名称列表，返回一个vector&lt;std::string&gt;对象，存储所有已注册的特征实例的命名名称；按注册顺序存储；Vector中的featureName不存在重复的名称。</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p8344182572313"><a name="p8344182572313"></a><a name="p8344182572313"></a>NA</p>
</td>
</tr>
<tr id="row2026121672514"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p13910175255"><a name="p13910175255"></a><a name="p13910175255"></a>static std::shared_ptr&lt;FeatureInterpreter&gt;</p>
<p id="p3941719251"><a name="p3941719251"></a><a name="p3941719251"></a><strong id="b282652352515"><a name="b282652352515"></a><a name="b282652352515"></a>GetFeatureInterpreterByFeatureName</strong>(const std::string &amp;featureName)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p32631642515"><a name="p32631642515"></a><a name="p32631642515"></a>根据传入的特征实例命名获取对应的特征实例。</p>
<p id="p1231904112519"><a name="p1231904112519"></a><a name="p1231904112519"></a><strong id="b15627147102513"><a name="b15627147102513"></a><a name="b15627147102513"></a>返回值：</strong></p>
<p id="p1192094362512"><a name="p1192094362512"></a><a name="p1192094362512"></a>featureInterpreter，实例化针对该调用方的管理类，使用方通过该对象管理模型推理实例。</p>
<p id="p16256912132612"><a name="p16256912132612"></a><a name="p16256912132612"></a><strong id="b68921514172618"><a name="b68921514172618"></a><a name="b68921514172618"></a>nullptr:</strong></p>
<a name="ol1814319351858"></a><a name="ol1814319351858"></a><ol id="ol1814319351858"><li>featureName不在特征实例 List中</li></ol>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p142651662517"><a name="p142651662517"></a><a name="p142651662517"></a>const std::string &amp;featureName: 要获取特征实例的特征命名名称</p>
</td>
</tr>
<tr id="row567415071811"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p679983171818"><a name="p679983171818"></a><a name="p679983171818"></a>static ReturnCode <strong id="b1799143151814"><a name="b1799143151814"></a><a name="b1799143151814"></a>GetFrameworkInfo</strong>(const std::string &amp;frameworkName, FrameworkInfo&amp; frameworkInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p1379920312182"><a name="p1379920312182"></a><a name="p1379920312182"></a>获取框架信息</p>
<p id="p1279911331812"><a name="p1279911331812"></a><a name="p1279911331812"></a><strong id="b1079912321817"><a name="b1079912321817"></a><a name="b1079912321817"></a>返回值</strong>：</p>
<p id="p979920315184"><a name="p979920315184"></a><a name="p979920315184"></a>SUCCESS    获取框架信息成功</p>
<p id="p16799934181"><a name="p16799934181"></a><a name="p16799934181"></a>INVALID_PARAM  无效的框架信息参数</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p197991535185"><a name="p197991535185"></a><a name="p197991535185"></a>const std::string &amp;frameworkName: 要查询的推理框架名称</p>
<p id="p11799183121818"><a name="p11799183121818"></a><a name="p11799183121818"></a>FrameworkInfo&amp; frameworkInfo: 查询到的推理框架信息</p>
</td>
</tr>
<tr id="row57941414102811"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p988515155281"><a name="p988515155281"></a><a name="p988515155281"></a>static std::shared_ptr&lt;ModelInterpreter&gt;</p>
<p id="p888541514285"><a name="p888541514285"></a><a name="p888541514285"></a><strong id="b1924121842818"><a name="b1924121842818"></a><a name="b1924121842818"></a>GetModelInterpreterByModelName</strong>(const std::string &amp;modelName)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p8794161422817"><a name="p8794161422817"></a><a name="p8794161422817"></a>根据传入的模型推理实例命名获取对应的模型推理实例</p>
<p id="p52978318287"><a name="p52978318287"></a><a name="p52978318287"></a><strong id="b67271741162812"><a name="b67271741162812"></a><a name="b67271741162812"></a>返回值：</strong>modelInterpreter，实例化针对该调用方的管理类，使用方通过该对象调用推理相关接口。</p>
<p id="p10898651959"><a name="p10898651959"></a><a name="p10898651959"></a><strong id="b1389895554"><a name="b1389895554"></a><a name="b1389895554"></a>返回nullptr的情况:</strong></p>
<a name="ol152934471359"></a><a name="ol152934471359"></a><ol id="ol152934471359"><li>modelName不在推理实例List中；</li></ol>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p37941614112814"><a name="p37941614112814"></a><a name="p37941614112814"></a>const std::string &amp;modelName: 模型推理实例命名名称</p>
</td>
</tr>
<tr id="row95899015272"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p1158911016279"><a name="p1158911016279"></a><a name="p1158911016279"></a>static std::vector&lt;std::string&gt;<strong id="b141306614274"><a name="b141306614274"></a><a name="b141306614274"></a>GetModelNameList</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p1958911002715"><a name="p1958911002715"></a><a name="p1958911002715"></a>获取所有已创建的模型推理实例命名的名称列表</p>
<p id="p1656918214276"><a name="p1656918214276"></a><a name="p1656918214276"></a><strong id="b797542710277"><a name="b797542710277"></a><a name="b797542710277"></a>返回值：</strong>模型推理实例命名名称列表，返回一个vector&lt;std::string&gt;对象，存储所有已创建的模型推理实例的命名名称；按注册顺序存储；Vector中的modelName不存在重复的名称。</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p1558990192716"><a name="p1558990192716"></a><a name="p1558990192716"></a>NA</p>
</td>
</tr>
<tr id="row746820204576"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p1346872013573"><a name="p1346872013573"></a><a name="p1346872013573"></a>static std::shared_ptr&lt;FeatureInterpreter&gt; <strong id="b421821795919"><a name="b421821795919"></a><a name="b421821795919"></a>RegisterFeature</strong>(const FeatureConfig&amp; featureConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p1446818207575"><a name="p1446818207575"></a><a name="p1446818207575"></a>向DLLite-Micro控制面注册特性信息，初始化配置，设置featureName(不可重复)。返回后续调用所使用的实例化管理类。featureInterpreter</p>
<p id="p10627534185910"><a name="p10627534185910"></a><a name="p10627534185910"></a><strong id="b9615121208"><a name="b9615121208"></a><a name="b9615121208"></a>返回值：</strong>featureInterpreter 实例化针对该调用方的管理类，使用方通过该对象管理模型推理实例。</p>
<p id="p183801451"><a name="p183801451"></a><a name="p183801451"></a><strong id="b11838211257"><a name="b11838211257"></a><a name="b11838211257"></a>返回nullptr的情况:</strong></p>
<a name="ol104881537415"></a><a name="ol104881537415"></a><ol id="ol104881537415"><li>featureName长度超过上限(最大256)</li><li>注册数量达到上限(每个进程8个)</li><li>featureName已被注册</li></ol>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p646862013578"><a name="p646862013578"></a><a name="p646862013578"></a>const FeatureConfig&amp; featurConfig: 应用配置信息，包括特性名称(featureName)</p>
</td>
</tr>
<tr id="row16468152012576"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p19468192010573"><a name="p19468192010573"></a><a name="p19468192010573"></a>static ReturnCode <strong id="b91878014416"><a name="b91878014416"></a><a name="b91878014416"></a>UnregisterFeature</strong>(std::shared_ptr&lt;FeatureInterpreter&gt; &amp;featureInterpreter)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p646822018574"><a name="p646822018574"></a><a name="p646822018574"></a>向DLLite-Micro控制面板反注册特性信息，并释放相关资源。</p>
<p id="p1665519231042"><a name="p1665519231042"></a><a name="p1665519231042"></a><strong id="b1137413316413"><a name="b1137413316413"></a><a name="b1137413316413"></a>返回值：</strong></p>
<p id="p1297912331849"><a name="p1297912331849"></a><a name="p1297912331849"></a>SUCCESS  反注册特性信息成功</p>
<p id="p29791833342"><a name="p29791833342"></a><a name="p29791833342"></a>UNKNOWN  特征实例数量为0</p>
<p id="p149791331442"><a name="p149791331442"></a><a name="p149791331442"></a>INVALID_POINTER  无效的featureInterpreter实例化</p>
<p id="p29790332419"><a name="p29790332419"></a><a name="p29790332419"></a>INVALID_PARAM    此特征实例不在特征实例list中</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p1746882075712"><a name="p1746882075712"></a><a name="p1746882075712"></a>std::shared_ptr&lt;FeatureInterpreter&gt; &amp;featureInterpreter: 注册时获得的应用推理管理类</p>
</td>
</tr>
<tr id="row1042614501554"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p1742665020513"><a name="p1742665020513"></a><a name="p1742665020513"></a>std::shared_ptr&lt;ModelInterpreter&gt; <strong id="b1017185115717"><a name="b1017185115717"></a><a name="b1017185115717"></a>CreateModelInterpreter</strong>(const ModelConfig &amp;modelConfig)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p1342613507516"><a name="p1342613507516"></a><a name="p1342613507516"></a>获取模型的推理实例，同一个模型可以生成多个推理实例。</p>
<p id="p1435425510815"><a name="p1435425510815"></a><a name="p1435425510815"></a><strong id="b978112181691"><a name="b978112181691"></a><a name="b978112181691"></a>返回值：</strong>modelInterpreter 模型推理实例。如果为nullptr则创建失败，否则创建成功。通过返回的ModelInterpreter指针可以继续调用其load、invoke等方法，该实例所包含接口见后续接口。</p>
<p id="p3435102131019"><a name="p3435102131019"></a><a name="p3435102131019"></a><strong id="b1671211444101"><a name="b1671211444101"></a><a name="b1671211444101"></a>返回nullptr的情况:</strong></p>
<a name="ol15435192111106"></a><a name="ol15435192111106"></a><ol id="ol15435192111106"><li>modelName长度超过上限(最大256)</li><li>modelName为空</li><li>modelPath长度达到最大上限（最大256）</li><li>weightPath长度达到最大上限（最大256）</li><li>模型大小超过300KB</li><li>模型为空文件</li><li>创建数量达到上限(每个特征实例16个)</li><li>modelName已被创建使用</li></ol>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p8127162818910"><a name="p8127162818910"></a><a name="p8127162818910"></a>const ModelConfig &amp;modelConfig: 模型配置信息</p>
</td>
</tr>
<tr id="row636964111113"><td class="cellrowborder" valign="top" width="34.870000000000005%" headers="mcps1.2.4.1.1 "><p id="p536918411112"><a name="p536918411112"></a><a name="p536918411112"></a>ReturnCode <strong id="b8485101616196"><a name="b8485101616196"></a><a name="b8485101616196"></a>DestroyModelInterpreter</strong> (std::shared_ptr&lt;ModelInterpreter&gt;&amp;  modelInterpreter)</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.2.4.1.2 "><p id="p33693401118"><a name="p33693401118"></a><a name="p33693401118"></a>销毁所传入的推理实例，释放相应资源。</p>
<p id="p1446863551910"><a name="p1446863551910"></a><a name="p1446863551910"></a><strong id="b436355042219"><a name="b436355042219"></a><a name="b436355042219"></a>返回值：</strong></p>
<p id="p43747383192"><a name="p43747383192"></a><a name="p43747383192"></a>SUCCESS    销毁模型推理实例成功</p>
<p id="p637416381191"><a name="p637416381191"></a><a name="p637416381191"></a>INVALID_PARAM    无效的推理模型实例</p>
</td>
<td class="cellrowborder" valign="top" width="29.18%" headers="mcps1.2.4.1.3 "><p id="p33691481120"><a name="p33691481120"></a><a name="p33691481120"></a>std::shared_ptr&lt;ModelInterpreter&gt;&amp;  modelInterpreter：待销毁的模型推理实例</p>
</td>
</tr>
</tbody>
</table>

## model\_interpreter.h<a name="section18190171223412"></a>

**表 10**  model\_interpreter中定义的常量

<a name="table176681414175113"></a>
<table><thead align="left"><tr id="row66681914105120"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p4668214105117"><a name="p4668214105117"></a><a name="p4668214105117"></a>常量名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p136680144514"><a name="p136680144514"></a><a name="p136680144514"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p18668121412516"><a name="p18668121412516"></a><a name="p18668121412516"></a>常量值</p>
</th>
</tr>
</thead>
<tbody><tr id="row36681914175116"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p146692140519"><a name="p146692140519"></a><a name="p146692140519"></a>IOFlag</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p176691414135116"><a name="p176691414135116"></a><a name="p176691414135116"></a>IO标志枚举值</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p19368754724"><a name="p19368754724"></a><a name="p19368754724"></a>INPUT</p>
<p id="p1236815541624"><a name="p1236815541624"></a><a name="p1236815541624"></a>OUTPUT</p>
</td>
</tr>
</tbody>
</table>

**表 11**  ModelInterpreter类接口

<a name="table1584211619315"></a>
<table><thead align="left"><tr id="row13842131619313"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p116642302318"><a name="p116642302318"></a><a name="p116642302318"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1466453033119"><a name="p1466453033119"></a><a name="p1466453033119"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p26649301319"><a name="p26649301319"></a><a name="p26649301319"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row10842191663117"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1248112581576"><a name="p1248112581576"></a><a name="p1248112581576"></a>ReturnCode <strong id="b1120953914583"><a name="b1120953914583"></a><a name="b1120953914583"></a>Load</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p675210456582"><a name="p675210456582"></a><a name="p675210456582"></a>加载模型。轻量级框架是纯C化的模型，模型实际上是.so库；加载模型动态库，创建会话，获取模型输入输出Tensor信息。</p>
<p id="p208479017596"><a name="p208479017596"></a><a name="p208479017596"></a><strong id="b18750136105916"><a name="b18750136105916"></a><a name="b18750136105916"></a>返回值：</strong></p>
<p id="p132491740594"><a name="p132491740594"></a><a name="p132491740594"></a>SUCCESS    加载模型成功</p>
<p id="p1971949184710"><a name="p1971949184710"></a><a name="p1971949184710"></a>LOAD_REPEATED  模型已被加载</p>
<p id="p111247102525"><a name="p111247102525"></a><a name="p111247102525"></a>INVALID_POINTER    空指针</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5842916163118"><a name="p5842916163118"></a><a name="p5842916163118"></a>NA</p>
</td>
</tr>
<tr id="row084271618317"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p2843216183112"><a name="p2843216183112"></a><a name="p2843216183112"></a>ReturnCode <strong id="b64771045125911"><a name="b64771045125911"></a><a name="b64771045125911"></a>Unload</strong>()</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1284361619311"><a name="p1284361619311"></a><a name="p1284361619311"></a>卸载模型，释放输入/输出推理内存资源</p>
<p id="p1316311535598"><a name="p1316311535598"></a><a name="p1316311535598"></a><strong id="b1874296401"><a name="b1874296401"></a><a name="b1874296401"></a>返回值：</strong></p>
<p id="p129131301009"><a name="p129131301009"></a><a name="p129131301009"></a>SUCCESS    模型卸载成功</p>
<p id="p1473017605510"><a name="p1473017605510"></a><a name="p1473017605510"></a>UNLOAD_REPEATED    模型已卸载</p>
<p id="p617194017555"><a name="p617194017555"></a><a name="p617194017555"></a>INVALID_POINTER    空指针</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p784371613112"><a name="p784371613112"></a><a name="p784371613112"></a>NA</p>
</td>
</tr>
<tr id="row10843171693117"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p484381612319"><a name="p484381612319"></a><a name="p484381612319"></a>ReturnCode <strong id="b6248132109"><a name="b6248132109"></a><a name="b6248132109"></a>CreateTensors</strong>(std::vector&lt;IOTensor&gt;&amp; tensors, IOFlag flag)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1984316164315"><a name="p1984316164315"></a><a name="p1984316164315"></a>创建Tensor并申请内存</p>
<p id="p88547547012"><a name="p88547547012"></a><a name="p88547547012"></a><strong id="b192181741716"><a name="b192181741716"></a><a name="b192181741716"></a>返回值：</strong></p>
<p id="p6345658707"><a name="p6345658707"></a><a name="p6345658707"></a>SUCCESS    创建Tensor并申请内存成功</p>
<p id="p14997810125920"><a name="p14997810125920"></a><a name="p14997810125920"></a>LOAD_NOT_EXECUTED    模型未加载</p>
<p id="p122151411119"><a name="p122151411119"></a><a name="p122151411119"></a>INVALID_PARAM    无效的输入/输出标识</p>
<p id="p156683210011"><a name="p156683210011"></a><a name="p156683210011"></a></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p118431316203118"><a name="p118431316203118"></a><a name="p118431316203118"></a>std::vector&lt;IOTensor&gt; &amp;tensors: 待创建的tensor</p>
<p id="p14634859811"><a name="p14634859811"></a><a name="p14634859811"></a>IOFlag flag: 输入/输出标识</p>
<p id="p233435152120"><a name="p233435152120"></a><a name="p233435152120"></a>（此接口当前版本暂不支持，后续版本中完善功能。当前版本返回ReturnCode::UNSUPPORTED_API）</p>
</td>
</tr>
<tr id="row78431216123110"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p884313164313"><a name="p884313164313"></a><a name="p884313164313"></a>ReturnCode <strong id="b917114320310"><a name="b917114320310"></a><a name="b917114320310"></a>DestroyTensors</strong>(std::vector&lt;IOTensor&gt;&amp; tensors)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p884321618314"><a name="p884321618314"></a><a name="p884321618314"></a>释放创建的Tensors资源</p>
<p id="p16504101717312"><a name="p16504101717312"></a><a name="p16504101717312"></a><strong id="b1846120225310"><a name="b1846120225310"></a><a name="b1846120225310"></a>返回值</strong>：</p>
<p id="p980610321636"><a name="p980610321636"></a><a name="p980610321636"></a>SUCCESS    释放Tensors资源成功</p>
<p id="p17677190125"><a name="p17677190125"></a><a name="p17677190125"></a>LOAD_NOT_EXECUTED    模型未加载</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p108431169313"><a name="p108431169313"></a><a name="p108431169313"></a>std::vector&lt;IOTensor&gt; &amp;tensors: 待释放的tensor</p>
<p id="p64001417124714"><a name="p64001417124714"></a><a name="p64001417124714"></a>（此接口当前版本暂不支持，后续版本中完善功能。当前版本返回ReturnCode::UNSUPPORTED_API）</p>
</td>
</tr>
<tr id="row1484310167319"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p128437168319"><a name="p128437168319"></a><a name="p128437168319"></a>ReturnCode <strong id="b2624381146"><a name="b2624381146"></a><a name="b2624381146"></a>GetTensors</strong>(std::vector&lt;IOTensor&gt; &amp;tensors, IOFlag flag) const</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p78431165318"><a name="p78431165318"></a><a name="p78431165318"></a>获取Tensor信息</p>
<p id="p143751058143"><a name="p143751058143"></a><a name="p143751058143"></a><strong id="b1337514581042"><a name="b1337514581042"></a><a name="b1337514581042"></a>返回值</strong>：</p>
<p id="p537510581542"><a name="p537510581542"></a><a name="p537510581542"></a>SUCCESS    获取Tensor信息成功</p>
<p id="p2010683465715"><a name="p2010683465715"></a><a name="p2010683465715"></a>INVALID_POINTER    空指针</p>
<p id="p1937511581843"><a name="p1937511581843"></a><a name="p1937511581843"></a>INVALID_PARAM 无效的输入/输出标识</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1986560141410"><a name="p1986560141410"></a><a name="p1986560141410"></a>std::vector&lt;IOTensor&gt; &amp;tensors: 待创建的tensor</p>
<p id="p108650012142"><a name="p108650012142"></a><a name="p108650012142"></a>IOFlag flag: 输入/输出标识</p>
</td>
</tr>
<tr id="row1384301683115"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17843111643119"><a name="p17843111643119"></a><a name="p17843111643119"></a>ReturnCode <strong id="b103836197719"><a name="b103836197719"></a><a name="b103836197719"></a>Invoke</strong>(std::vector&lt;IOTensor&gt; &amp;inputs, std::vector&lt;IOTensor&gt; &amp;outputs) const</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10843191610316"><a name="p10843191610316"></a><a name="p10843191610316"></a>对inputs中的输入数据进行推理，并将推理结果通过输出至outputs。</p>
<p id="p468731120812"><a name="p468731120812"></a><a name="p468731120812"></a><strong id="b116871811686"><a name="b116871811686"></a><a name="b116871811686"></a>返回值</strong>：</p>
<p id="p1687311480"><a name="p1687311480"></a><a name="p1687311480"></a>SUCCESS    推理成功</p>
<p id="p14673135233"><a name="p14673135233"></a><a name="p14673135233"></a>LOAD_NOT_EXECUTED    模型已加载</p>
<p id="p18900981047"><a name="p18900981047"></a><a name="p18900981047"></a>INVALID_POINTER    空指针</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p174604372817"><a name="p174604372817"></a><a name="p174604372817"></a>std::vector&lt;IOTensor&gt; &amp;inputs:<strong id="b14224124015333"><a name="b14224124015333"></a><a name="b14224124015333"></a> </strong>输入tensor</p>
<p id="p17843316183118"><a name="p17843316183118"></a><a name="p17843316183118"></a>std::vector&lt;IOTensor&gt; &amp;outputs: 输出tensor</p>
</td>
</tr>
</tbody>
</table>

