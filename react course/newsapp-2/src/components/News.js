import React, { useEffect, useState } from 'react'
import NewsItem from './NewsItem'
import Spinner from './Spinner';
import PropTypes from 'prop-types'
import InfiniteScroll from "react-infinite-scroll-component"
import props from 'prop-types';

const News = ({ setProgress, country, pageSize, category }) => {

    const [articles, setArticles] = useState([])
    const [loading, setLoading] = useState(false)
    const [page, setPage] = useState(1)
    const [totalResults, setTotalResults] = useState(0)

    const updateNews = async (props) => {
        setProgress(10);
        const url = `https://newsapi.org/v2/top-headlines?country=${country}&category=${category}&apiKey=692b31ad448e44898e2e081aca8f0ef3&page=${page}&pageSize=${pageSize}`;
        setLoading(true);
        let data = await fetch(url);
        let parsedData = await data.json();
        // console.log(parsedData);
        setArticles(parsedData.articles);
        setTotalResults(parsedData.totalResults);
        setLoading(false);

        setProgress(100);
    }

    useEffect(() => {
        updateNews();
    }, [])


    const handlePrevClick = async () => {
        // console.log("prev");

        // let url = `https://newsapi.org/v2/top-headlines?country=${country}&category=${category}&apiKey=692b31ad448e44898e2e081aca8f0ef3&page=${this.state.page - 1}&pageSize=${pageSize}`;
        // this.setState({ loading: true });
        // let data = await fetch(url);
        // let parsedData = await data.json();


        // this.setState({
        //     page: this.state.page - 1,
        //     articles: parsedData.articles,
        //     loading: false,
        // });
        setPage(page - 1);

        updateNews()
    }

    const handleNextClick = async () => {
        // console.log("next");

        // let url = `https://newsapi.org/v2/top-headlines?country=${country}&category=${category}&apiKey=692b31ad448e44898e2e081aca8f0ef3&page=${this.state.page + 1}&pageSize=${pageSize}`;
        // this.setState({ loading: true });
        // let data = await fetch(url);
        // let parsedData = await data.json();


        // this.setState({
        //     page: this.state.page + 1,
        //     articles: parsedData.articles,
        //     loading: false,
        // })
        setPage(page+1);
        updateNews();

    }

    const fetchMoreData = async () => {
        setPage(page + 1);
        const url = `https://newsapi.org/v2/top-headlines?country=${country}&category=${category}&apiKey=692b31ad448e44898e2e081aca8f0ef3&page=${page}&pageSize=${pageSize}`;
        setLoading(true);
        let data = await fetch(url);
        let parsedData = await data.json();
        // console.log(parsedData);
        setArticles(articles.concat(parsedData.articles));
        setTotalResults(parsedData.totalResults);
        setLoading(false);
    }

    return (
        <>
            <h1 className="text-center" style={{ margin: '30px 0px' }}>NewNews Top Headlines</h1>
            {/* {this.state.loading && <Spinner />} */}

            <InfiniteScroll
                dataLength={articles.length}
                next={fetchMoreData}
                hasMore={articles.length !== totalResults}
                loader={<Spinner />}
            >

                <div className="container">
                    <div className="row">
                        {articles.map((element) => {
                            return <div className="col-md-4" key={element.url}>
                                {/* <NewsItem title={element.title.slice(0, 40)} description={element.description && element.description.slice(0, 80)} imageUrl={element.urlToImage} newsUrl={element.url} /> */}
                                <NewsItem title={element.title} description={element.description && element.description} imageUrl={element.urlToImage} newsUrl={element.url} author={element.author ? element.author : "Unknown"} date={element.publishedAt} source={element.source.name} />
                            </div>
                        })}
                    </div>
                </div>
            </InfiniteScroll>
            {/* <div className="container d-flex justify-content-between">
                    <button disabled={this.state.page <= 1} type="button" className="btn btn-warning btn-lg" onClick={this.handlePrevClick}>&larr; Previous</button>
                    <button disabled={this.state.page + 1 > Math.ceil(this.state.totalResults / pageSize)} type="button" className="btn btn-warning btn-lg" onClick={this.handleNextClick}>Next &rarr;</button>
                </div> */}
        </>
    )
}

News.defaultProps = {
    country: 'in',
    pageSize: 8,
    category: 'general',
    setProgress:10
}

News.propTypes = {
    country: PropTypes.string,
    pageSize: PropTypes.number,
    category: PropTypes.string,
}

export default News